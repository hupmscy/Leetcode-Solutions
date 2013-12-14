class Solution {
public:
    #define SIZE 5000
    int dp[SIZE];
    char str[SIZE];

    bool is_palindrome(char str[], int l, int r)
    {
        for (int i = l; i <= (l+r)/2; i++)
            if (str[i] != str[r-i+l])
                return false;
        return true;
    }

    int minCut(string s) {
        if (s.size() == 0)
            return 0;
        memset(dp, -1, sizeof(dp));
        strcpy(str, s.c_str());
        for (int i = 1; i <= s.size(); i++)
        {
            int min_v = INT_MAX;
            for (int j = i-1; j >= 0; j--)
                if (is_palindrome(str, j, i-1) && (j == 0 || (dp[j] != -1 && min_v > dp[j])))
                    min_v = dp[j];
            dp[i] = min_v + 1;
        }
        return dp[s.size()];
    }
};
