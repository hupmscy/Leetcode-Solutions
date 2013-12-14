class Solution {
public:

    int numDistinct(string S, string T) {
        if (S.size() == 0 || T.size() == 0)
            return 0;
        int len1 = S.size();
        int len2 = T.size();
        int dp[len1+1][len2+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= len1; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= len2; j++)
        {
            if (S[j-1] == T[j-1] && dp[j-1][j-1])
                dp[j][j] = 1;
            for (int i = j+1; i <= len1; i++)
            {
                dp[i][j] = dp[i-1][j];
                if (S[i-1] == T[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[len1][len2];
    }
};
