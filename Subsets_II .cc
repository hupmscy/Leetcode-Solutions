class Solution {
public:
    int ele[100];
    void search(int start, int step, int n, vector<int> &S, vector<vector<int> > &ans)
    {
        if (step == n)
        {
            vector<int> tmp;
            for (int i = 0; i < step; i++)
                tmp.push_back(ele[i]);
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < S.size(); i++)
        {
            if (i > start && S[i] == S[i-1])
                continue;
            ele[step] = S[i];
            search(i+1, step+1, n, S, ans);
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        sort(S.begin(), S.end());
        for (int i = 1; i <= S.size(); i++)
            search(0, 0, i, S, ans);
        return ans;
    }
};
