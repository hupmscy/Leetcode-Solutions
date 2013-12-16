class Solution {
public:
    int seq[100];
    bool visit[100];
    void dfs(int step, int n, vector<int> &num, vector<vector<int> > &ans)
    {
        if (step == n)
        {
            vector<int> tmp;
            for (int i = 0; i < step; i++)
                tmp.push_back(num[seq[i]]);
            ans.push_back(tmp);
            return;
        }
        int unvisit[n+1], i, k;
        k = 0;
        for (i = 0; i < n; i++)
            if (!visit[i])
                unvisit[k++] = i;
        for (i = 0; i < k; i++)
        {
            if (i > 0 && num[unvisit[i]] == num[unvisit[i-1]])
                continue;
            visit[unvisit[i]] = true;
            seq[step] = unvisit[i];
            dfs(step+1, n, num, ans);
            visit[unvisit[i]] = false;
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> >ans;
        if (num.size() == 0)
            return ans;
        int n = num.size();
        sort(num.begin(), num.end());
        memset(visit, false, sizeof(visit));
        dfs(0, n, num, ans);
        return ans;
    }
};
