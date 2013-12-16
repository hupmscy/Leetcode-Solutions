class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[2][n+10];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                dp[i%2][j] = 1;
            else if (i == 1)
                dp[i%2][j] = dp[i%2][j-1];
            else if (j == 1)
                dp[i%2][j] = dp[(i-1)%2][j];
            else
                dp[i%2][j] = dp[i%2][j-1] + dp[(i-1)%2][j];
        }
        return dp[m%2][n];
    }
};
