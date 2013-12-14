class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len3 != len1+len2)
            return false;
        int i, j, k;
        bool dp[len1+1][len2+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (i = 0; i < len1; i++)
            if (s1[i] == s3[i])
                dp[i+1][0] = true;
            else
                break;
        for (i = 0; i < len2; i++)
            if (s2[i] == s3[i])
                dp[0][i+1] = true;
            else
                break;
        for (k = 2; k <= len3; k++)
        {
            for (i = 1; i < k; i++)
                if (i <= len1 && k-i <= len2 && ((s1[i-1] == s3[k-1] && dp[i-1][k-i]) || (dp[i][k-i-1] && s2[k-i-1] == s3[k-1])))
                    dp[i][k-i] = true;
        }
        for (i = 0; i <= len3; i++)
            if (i <= len1 && len3-i <= len2 && dp[i][len3-i])
                return true;
        return false;
    }
};
