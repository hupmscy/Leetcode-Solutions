class Solution {
public:
    #define SIZE 20
    bool row[SIZE][SIZE], col[SIZE][SIZE], sub[SIZE][SIZE];

    bool isValidSudoku(vector<vector<char> > &board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(sub, false, sizeof(sub));
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == '.')
                continue;
            int num = board[i][j]-48;
            if (!row[i][num] && !col[j][num] && !sub[i/3*3+j/3][num])
                row[i][num] = col[j][num] = sub[i/3*3+j/3][num] = true;
            else
                return false;
        }
        return true;
    }
};
