class Solution {
public:

    #define SIZE 10000

    struct E
    {
        int t, next;
    };

    E edge[SIZE*4];
    int head[SIZE], pos;
    bool visit[SIZE];
    string str[SIZE];
    bool has_edge(const char *a, const char *b, int len)
    {
        int diff = 0;
        for (int i = 0; i < len; i++)
            if (a[i] != b[i])
            {
                diff++;
                if (diff > 1)
                    return false;
            }
        return diff ? true : false;
    }

    void add_edge(int a, int b)
    {
        edge[pos].next = head[a];
        edge[pos].t = b;
        head[a] = pos++;
    }

    int bfs(int s, int t)
    {
        queue<pair<int, int>> q;
        pair<int, int> tmp;
        int cur, step;
        visit[s] = true;
        q.push(make_pair(s, 1));
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            cur = tmp.first;
            step = tmp.second;
            if (cur == t)
                return step;
            for (int i = head[cur]; i != -1; i = edge[i].next)
            {
                int v = edge[i].t;
                if (!visit[v])
                {
                    visit[v] = true;
                    q.push(make_pair(v, step+1));
                }
            }
        }

        return 0;
    }

    int ladderLength(string start, string end, unordered_set<string> &dict) {
       if (dict.find(start) == dict.end())
        dict.insert(start);
       if (dict.find(end) == dict.end())
        dict.insert(end);
       unordered_map<string, int> lookup;
       int i = 0, sid, eid;
       int len = start.size();
       memset(head, -1, sizeof(head));
       memset(visit, false, sizeof(visit));
       pos = 0;

       for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)
       {
           lookup[*iter] = i;
           if (*iter == start)
            sid = i;
            if (*iter == end)
             eid = i;
            str[i] = *iter;
            i++;
       }

       for (int j = 0; j < i; j++)
       for (int k = j+1; k < i; k++)
            if(has_edge(str[j].c_str(), str[k].c_str(), len))
            {
                add_edge(k, j);
                add_edge(j, k);
            }
       return bfs(sid, eid);
    }
};
