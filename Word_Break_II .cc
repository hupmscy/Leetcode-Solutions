class Solution {
public:
    int n;
    void dfs(int pos, vector<vector<int> > &ind, string str, vector<string> &ans, char s[])
    {
        if (pos == 0)
        {
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < ind[pos].size(); i++)
        {
            int start = ind[pos][i];
            if (pos == n)
                dfs(start, ind, string(s+start, pos-start), ans, s);
            else
                dfs(start, ind, string(s+start, pos-start) + " " + str, ans, s);
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ans;
        if (s.size() == 0 || dict.size() == 0)
            return ans;
        n = s.size();
        int i, j, k;
        int min_len, max_len;
        char str[n+5];
        strcpy(str, s.c_str());

        vector<vector<int>> ind(n+5);

        bool dp[n+5];
        memset(dp, false, sizeof(dp));

        dp[0] = true;

        min_len = INT_MAX;
        max_len = INT_MIN;
        for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); ++iter)
        {
            int size = (*iter).size();
            if (size > max_len)
                max_len = size;
            if (size < min_len)
                min_len = size;
        }

        for (i = min_len; i <= n; i++)
        {
            for (j = i-min_len; j >= max(0, i-max_len); j--)
            {
                string str = s.substr(j, i-j);
                if (dict.find(str) != dict.end() && dp[j])
                {
                    ind[i].push_back(j);
                    dp[i] = true;
                }
            }
        }
        dfs(n, ind, "", ans, str);

        return ans;
    }
};
