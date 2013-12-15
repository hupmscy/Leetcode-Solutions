class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0)
            return 0;
        int n = height.size();
        int st[n+10], llimit[n+10], rlimit[n+10], top, ans;
        top = 0;
        st[0] = -1;
        for (int i = 0; i < n; i++)
        {
            int h = height[i];
            while (top && height[st[top]] >= h)top--;
            llimit[i] = st[top]+1;
            st[++top] = i;
        }
        top = 0;
        st[0] = n;
        for (int i = n-1; i >= 0; i--)
        {
            int h = height[i];
            while (top && height[st[top]] >= h)top--;
            rlimit[i] = st[top]-1;
            st[++top] = i;
        }
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            int v = (rlimit[i]-llimit[i]+1)*height[i];
            if (v > ans)
                ans = v;
        }
        return ans;
    }
};
