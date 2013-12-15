class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        int n = s1.size();
        int i, j, k, l;
        bool dp[n+1][n+1][n+1];
        memset(dp, false, sizeof(dp));
        for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (s1[i] == s2[j])
                dp[i][j][1] = true;
        for (k = 2; k <= n; k++)
        for (i = 0; i+k-1 < n; i++)
        for (j = 0; j+k-1 < n; j++)
        {
            for (l = 1; l < k; l++)
                if ((dp[i][j][l] && dp[i+l][j+l][k-l]) || (dp[i][j+(k-l)][l] && dp[i+l][j][k-l]))
                {
                    dp[i][j][k] = true;
                    break;
                }
        }
        return dp[0][0][n];
    }
};
