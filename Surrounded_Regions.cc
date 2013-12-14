class Solution {
public:
    #define SIZE 500
    bool mark[SIZE][SIZE];
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int r, c;
    void bfs(vector<vector<char>> &board, int x, int y)
    {
        queue<pair<int, int> > q;
        pair<int, int> tmp;
        int cx, cy, nx, ny;
        mark[x][y] = true;
        q.push(make_pair(x, y));
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            cx = tmp.first;
            cy = tmp.second;
            for (int i = 0; i < 4; i++)
            {
                nx = cx+dir[i][0];
                ny = cy+dir[i][1];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && board[nx][ny] == 'O' && !mark[nx][ny])
                {
                    mark[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    void solve(vector<vector<char>> &board) {
        if (board.size() == 0)
            return;
        r = board.size();
        c = board[0].size();
        memset(mark, false, sizeof(mark));
        for (int i = 0; i < r; i++)
        {
            if (i == 0 || i == r-1)
            {
                for (int j = 0; j < c; j++)
                    if (board[i][j] == 'O')
                        bfs(board, i, j);
            }
            else
            {
                if (board[i][0] == 'O')
                    bfs(board, i, 0);
                if (board[i][c-1] == 'O')
                    bfs(board, i, c-1);
            }
        }
        for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (board[i][j] == 'O' && mark[i][j] == false)
                board[i][j] = 'X';
    }
};
