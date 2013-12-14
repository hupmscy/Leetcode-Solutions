class Solution {
public:
    #define SIZE 40000
    int dp[SIZE][3];
    int num[SIZE], n;
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int i, j, k, maxv;
        memset(dp, 0, sizeof(dp));
        n = prices.size()-1;
        for (i = 1; i < prices.size(); i++)
            num[i] = prices[i]-prices[i-1];

        for (j = 1; j <= 2; j++)
        {
            dp[j][j] = num[j]+dp[j-1][j-1];
            maxv = max(dp[j-1][j-1], dp[j][j-1]);
            for (i = j+1; i <= n; i++)
            {
                dp[i][j] = max(dp[i-1][j], maxv)+num[i];
                maxv = max(maxv, dp[i][j-1]);
            }
        }
        maxv = 0;
        for (j = 1; j <= 2; j++)
        for (i = j; i <= n; i++)
            if (dp[i][j] > maxv)
                maxv = dp[i][j];
        return maxv;
    }
};
