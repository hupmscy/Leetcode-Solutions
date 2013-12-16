class Solution {
public:
    int seq[100];
    void dfs(int start, int step, int cur_val, int target, vector<vector<int> > &ans, vector<int> &num)
    {

        if (cur_val == target)
        {
            vector<int> tmp;
            for (int i = 0; i < step; i++)
                tmp.push_back(seq[i]);
            ans.push_back(tmp);
            return;
        }
        if (start  >= num.size())
            return;
        for (int i = start; i < num.size(); i++)
        {
            if (cur_val + num[i] <= target)
            {
                seq[step] = num[i];
                dfs(i, step+1, cur_val+num[i], target, ans, num);
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> >ans;
        sort(candidates.begin(), candidates.end());
        dfs(0, 0, 0, target, ans, candidates);
        return ans;
    }
};
