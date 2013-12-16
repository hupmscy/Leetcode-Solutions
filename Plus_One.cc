class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (matrix.size() == 0)
            return;
        int x, y, i, j, r, c;
        x = -1;
        y = -1;
        r = matrix.size();
        c = matrix[0].size();
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
                if (matrix[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            if (j < c)
                break;
        }
        if (x == -1)
            return;
        for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (matrix[i][j] == 0)
            {
                matrix[x][j] = 0;
                matrix[i][y] = 0;
            }
        for (j = 0; j < c; j++)
        {
            if (j == y)
                continue;
            if (matrix[x][j] == 0)
            {
                for (int k = 0; k < r; k++)
                    matrix[k][j] = 0;
            }
        }
        for (i = 0; i < r; i++)
            if (matrix[i][y] == 0)
            {
                for (int k = 0; k < c; k++)
                    matrix[i][k] = 0;
            }
        for (i = 0; i < r; i++)
            matrix[i][y] = 0;
    }
};
