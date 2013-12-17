class Solution {
public:
    #define SIZE 15
    bool row[SIZE][SIZE], col[SIZE][SIZE], sub[SIZE][SIZE];

    bool dfs(int x, int y, vector<vector<char> > &board)
    {
        if (y == 9)
        {
            x++;
            y = 0;
        }
        if (x == 9)
            return true;

        if (board[x][y] != '.')
            return dfs(x, y+1, board);
        for (int i = 1; i <= 9; i++)
            if (!row[x][i] && !col[y][i] && !sub[x/3*3+y/3][i])
            {
                row[x][i] = col[y][i] = sub[x/3*3+y/3][i] = true;
                board[x][y] = i + 48;
                if (dfs(x, y+1, board))
                    return true;
                board[x][y] = '.';
                row[x][i] = col[y][i] = sub[x/3*3+y/3][i] = false;

            }
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(sub, false, sizeof(sub));
        for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j]-48;
            row[i][num] = col[j][num] = sub[i/3*3+j/3][num] = true;
        }
        dfs(0, 0, board);
    }
};
