class Solution {
public:
    bool col[50], diag[50], adiag[50];
    int ans, off;
    void dfs(int step, int n)
    {
        if (step == n)
        {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++)
            if (!col[i] && !diag[i-step+off] && !adiag[i+step])
            {
                col[i] = diag[i-step+off] = adiag[i+step] = true;
                dfs(step+1, n);
                col[i] = diag[i-step+off] = adiag[i+step] = false;
            }
    }

    int totalNQueens(int n) {
        if (!n)
            return 0;
        memset(col, false, sizeof(col));
        memset(diag, false, sizeof(diag));
        memset(adiag, false, sizeof(adiag));
        off = n;
        ans = 0;
        dfs(0, n);
        return ans;
    }
};
