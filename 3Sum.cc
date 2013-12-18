class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ans;
        if (num.size() == 0)
            return ans;
        int n = num.size();
        int i, j;
        sort(num.begin(), num.end());
        unordered_map<int, int> exist;
        for (i = n-1; i >= 0; i--)
            exist.insert(make_pair(num[i], i));
        for (i = 0; i < n-1; i++)
        {
            if (i > 0 && num[i-1] == num[i])
                continue;
            for (j = i+1; j < n-1; j++)
            {
                if (j > i+1 && num[j] == num[j-1])
                    continue;
                int v = 0-num[i]-num[j];
                if (exist.find(v) != exist.end() && exist[v] > j)
                {
                    vector<int> tmp(3);
                    tmp[0] = num[i];
                    tmp[1] = num[j];
                    tmp[2] = num[exist[v]];
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
};
