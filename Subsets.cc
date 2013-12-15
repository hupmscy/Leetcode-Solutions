class Solution {
public:
    int ele[100];
    void search(int start, int step, int n, vector<vector<int> > &ans, vector<int> &S)
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
            ele[step] = S[i];
            search(i+1, step+1, n, ans, S);
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ans;
        ans.push_back(vector<int>());
        sort(S.begin(), S.end());
        for (int i = 1; i <= S.size(); i++)
            search(0, 0, i, ans, S);
        return ans;
    }
};
