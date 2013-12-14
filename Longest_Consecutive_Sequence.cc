class Solution {
public:
    #define SIZE 10000
    bool visit[SIZE];
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0)
            return 0;

        unordered_map<int, int> exist;
        int ans = 1;
        memset(visit, false, sizeof(visit));

        for (int i = 0; i < num.size(); i++)
            exist[num[i]] = i;

        for (int i = 0; i < num.size(); i++)
            if (!visit[i])
            {
                int cur = 0;
                int j;
                for (j = num[i];;j++)
                    if (exist.find(j) != exist.end())
                        visit[exist[j]] = true;
                    else
                        break;
                cur += j-num[i];
                for (j = num[i]-1;; j--)
                    if (exist.find(j) != exist.end())
                        visit[exist[j]] = true;
                    else
                        break;
                cur += num[i]-j-1;
                if (cur > ans)
                    ans = cur;
            }
        return ans;
    }
};
