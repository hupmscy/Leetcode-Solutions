class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() <= 1)
            return 0;
        int l, r, ans;
        l = ans = 0;
        r = height.size()-1;
        while (l < r)
        {
            int v = min(height[l], height[r]);
            if (v*(r-l) > ans)
                ans = v*(r-l);
            if (height[l] > height[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};
