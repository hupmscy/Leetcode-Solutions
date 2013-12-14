class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int cur, ans, v, i;
        cur = ans = 0;
        for (i = 1; i < prices.size(); i++)
        {
            v = prices[i]-prices[i-1];
            cur += v;
            if (ans < cur)
                ans = cur;
            if (cur < 0)
                cur = 0;
        }
        return ans;
    }
};
