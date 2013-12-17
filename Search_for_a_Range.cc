class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ans(2, -1);
        int l, r;
        l = 0;
        r = n-1;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (A[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        if (A[l] != target)
            return ans;
        ans[0] = l;
        l = 0;
        r = n-1;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (A[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        ans[1] = r;
        return ans;
    }
};
