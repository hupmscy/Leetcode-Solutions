class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0)
            return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int st[m+10], col[m+10], llimit[m+10], rlimit[m+10], top;
        int i, j, k, ans = 0;
        memset(col, 0, sizeof(col));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                if (matrix[i][j] == '0')
                    col[j] = 0;
                else
                    col[j]++;
            top = 0;
            st[0] = -1;
            for (k = 0; k < m; k++)
            {
                int h = col[k];
                while (top && col[st[top]] >= h)top--;
                llimit[k] = st[top]+1;
                st[++top] = k;
            }
            top = 0;
            st[0] = m;
            for (k = m-1; k >= 0; k--)
            {
                int h = col[k];
                while (top && col[st[top]] >= h)top--;
                rlimit[k] = st[top]-1;
                st[++top] = k;
            }
            for (k = 0; k < m; k++)
            {
                int v = (rlimit[k]-llimit[k]+1)*col[k];
                if (v > ans)
                    ans = v;
            }
        }
        return ans;
    }
};
