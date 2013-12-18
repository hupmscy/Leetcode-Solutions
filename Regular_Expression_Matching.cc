class Solution {
public:
    bool isMatch(const char *s, const char *t) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!s || !t)
            return false;
        int len1 = strlen(s);
        int len2 = strlen(t);
        int len3;
        int i, j, k;
        char p1[len2+10];
        bool star[len2+10];
        memset(star, false, sizeof(star));
        for (i = len3 = 0; i < len2; i++)
        {
            if (t[i] != '*')
                p1[len3++] = t[i];
            else
                star[len3-1] = true;
        }

        bool dp[len1+10][len3+10];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= len3 && star[i-1]; i++)
            dp[0][i] = true;

        for (j = 1; j <= len3; j++)
        {
            if (star[j-1])
            {
                for (i = 1; i <= len1; i++)
                {
                    if (dp[i][j-1])
                    {
                        dp[i][j] = true;
                        continue;
                    }
                    if (p1[j-1] == s[i-1] || p1[j-1] == '.')
                    {
                        if (dp[i-1][j] || dp[i-1][j-1])
                        {
                            dp[i][j] = true;
                            continue;
                        }
                        k = i-1;
                        while (k > 0 && (p1[j-1] == s[k-1] || p1[j-1] == '.'))
                        {
                            if (dp[k-1][j-1])
                            {
                                dp[i][j] = true;
                                break;
                            }
                            k--;
                        }
                    }
                }
            }
            else if (p1[j-1] == '.')
            {
                for (i = 1; i <= len1; i++)
                    dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                for (i = 1; i <= len1; i++)
                    dp[i][j] = dp[i-1][j-1] && p1[j-1] == s[i-1];
            }
        }
        return dp[len1][len3];
    }
};
