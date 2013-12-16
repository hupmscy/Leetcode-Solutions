class Solution {
public:
    int seq[100];
    bool visit[100];

    void dfs(int step, int n, vector<int> &num, vector<vector<int> > &ans)
    {
        if (step == n)
        {
            vector<int> tmp;
            for (int i = 0; i < n; i++)
                tmp.push_back(num[seq[i]]);
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++)
            if (!visit[i])
            {
                visit[i] = true;
                seq[step] = i;
                dfs(step+1, n, num, ans);
                visit[i] = false;
            }
    }

    vector<vector<int> > permute(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> >ans;
        if (num.size() == 0)
            return ans;
        int n = num.size();
        memset(visit, false, sizeof(visit));
        dfs(0, n, num, ans);
        return ans;
    }
};
