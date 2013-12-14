class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        if (numRows == 0)
            return ans;
        int i, j;
        for (i = 0; i < numRows; i++)
        {
            vector<int> tmp;
            tmp.push_back(1);
            for (j = 1; j < i; j++)
                tmp.push_back(ans[i-1][j]+ans[i-1][j-1]);
            if (i > 0)
                tmp.push_back(1);
            ans.push_back(tmp);
        }
        return ans;
    }
};
