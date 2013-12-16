class Solution {
public:
    int maxSubArray(int A[], int n) {
        int cur, ans;
        ans = INT_MIN;
        cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur += A[i];
            if (cur > ans)
                ans = cur;
            if (cur < 0)
                cur = 0;
        }
        return ans;
    }
};
