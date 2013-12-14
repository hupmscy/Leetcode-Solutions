class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0, v, i;
        for (i = 1; i < prices.size(); i++)
        {
            v = prices[i]-prices[i-1];
            if (v > 0)
                ans += v;
        }
        return ans;
    }
};
