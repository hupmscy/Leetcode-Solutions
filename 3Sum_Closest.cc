\class Solution {
public:
    void update(vector<int> &num, int ind, int v, int &diff, int &ans, int i, int j)
    {
        if (abs(num[ind]-v) < diff)
            {
                diff = abs(num[ind]-v);
                ans = num[i]+num[j]+num[ind];
            }
    }

    int b_search(vector<int> &num, int l, int r, int target)
    {
        int r_org = r;
        int mid;
        while (l <= r)
        {
            mid = (l+r)/2;
            if (num[mid] < target)
                l = mid+1;
            else
                r = mid-1;
        }
        if (l > r_org)
            return r_org;
        return l;
    }

    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int i, j, ind, v, n, ans, diff;
        n = num.size();
        diff = INT_MAX;
        for (i = 0; i < n-1; i++)
        for (j = i+1; j < n-1; j++)
        {
            v = target-num[i]-num[j];
            ind = b_search(num, j+1, n-1, v);
            update(num, ind, v, diff, ans, i, j);
            if (diff == 0)
                return ans;
            if (ind-1 > j)
                update(num, ind-1, v, diff, ans, i, j);
        }
        return ans;
    }
};
