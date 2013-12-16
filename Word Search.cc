class Solution {
public:

    int row, col;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n;
    bool visit[500][500];

    bool dfs(int x, int y, int c, vector<vector<char> > &board, char s[])
    {
        if (c == n)
            return true;
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = x+dir[i][0];
            ny = y+dir[i][1];
            if (nx >=0 && nx < row && ny >= 0 && ny < col && !visit[nx][ny] && board[nx][ny] == s[c])
            {
                visit[nx][ny] = true;
                if (dfs(nx, ny, c+1, board, s))
                    return true;
                visit[nx][ny] = false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0)
            return false;
        row = board.size();
        col = board[0].size();
        int i, j;
        n = word.size();
        char str[n+10];
        strcpy(str, word.c_str());
        for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
        {
            if (board[i][j] == word[0])
            {
                memset(visit, false, sizeof(visit));
                visit[i][j] = true;
                if (dfs(i, j, 1, board, str))
                    return true;
            }
        }
        return false;
    }
};
