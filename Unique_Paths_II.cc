class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &ob) {
        int m = ob.size();
        int n = ob[0].size();
        int dp[m+10][n+10];
        if (ob[0][0] == 1)
            return 0;
        memset(dp, 0, sizeof(dp));
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (ob[i-1][j-1])
                continue;
            if (i == 1 && j == 1)
                continue;
            else if (i == 1)
                dp[i][j] = dp[i][j-1];
            else if (j == 1)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
        }
        return dp[m][n];
    }
};
