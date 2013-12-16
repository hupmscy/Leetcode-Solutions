class Solution {
public:
    int ans, off;
    int pos[50];
    bool col[50], diag[50], adiag[50];

    char str[50];

    void dfs(int step, int n, vector<vector<string> > &ans)
    {
        if (step == n)
        {
            int i, j;
            vector<string> tmp;
            for (i = 0; i < n; i++)
            {
                str[pos[i]] = 'Q';
                tmp.push_back(str);
                str[pos[i]] = '.';
            }
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++)
            if (!col[i] && !diag[i-step+off] && !adiag[i+step])
            {
                col[i] = diag[i-step+off] = adiag[i+step] = true;
                pos[step] = i;
                dfs(step+1, n, ans);
                col[i] = diag[i-step+off] = adiag[i+step] = false;
            }
    }

    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<string> >ans;
        if (!n)
            return ans;
        memset(col, false, sizeof(col));
        memset(diag, false, sizeof(diag));
        memset(adiag, false, sizeof(adiag));
        for (int i = 0; i < n; i++)
            str[i] = '.';
        str[n] = 0;
        off = n;
        dfs(0, n, ans);
        return ans;
    }
};
