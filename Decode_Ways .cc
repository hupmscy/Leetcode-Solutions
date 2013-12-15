class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        int n = s.size();
        int dp[n+3];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            if (s[i-1] != '0')
                dp[i] = dp[i-1];
            if (i >= 2)
            {
                int v = (s[i-2]-48)*10 + (s[i-1]-48);
                if (v >= 10 && v <= 26)
                    dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
