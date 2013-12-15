class Solution {
public:

    int ele[100];

    void dfs(int start, int step, int k, int n, vector<vector<int> > &ans)
    {
        if (step == k)
        {
            vector<int> tmp;
            for (int i = 0; i < step; i++)
                tmp.push_back(ele[i]);
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            ele[step] = i;
            dfs(i+1, step+1, k, n, ans);
        }
    }

    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ans;
        dfs(1, 0, k, n, ans);
        return ans;
    }
};
