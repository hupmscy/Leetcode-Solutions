class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ans;
        int r = matrix.size();
        if (r <= 0)
            return ans;
        int c = matrix[0].size();
        bool visit[r+10][c+10];
        memset(visit, false, sizeof(visit));
        int x, y, dx, dy;
        x = y = 0;
        dx = 0;
        dy = 1;
        for (int i = 0; i < r*c; i++)
        {
            ans.push_back(matrix[x][y]);
            visit[x][y] = true;
            if (dx == 0 && dy == 1 && (y+1 >= c || visit[x][y+1]))
            {
                dx = 1;
                dy = 0;
            }
            else if (dx == 1 && dy == 0 && (x+1 >= r || visit[x+1][y]))
            {
                dx = 0;
                dy = -1;
            }
            else if (dx == 0 && dy == -1 && (y-1 < 0 || visit[x][y-1]))
            {
                dx = -1;
                dy = 0;
            }
            else if (dx == -1 && dy == 0 && (x-1 < 0 || visit[x-1][y]))
            {
                dx = 0;
                dy = 1;
            }
            x += dx;
            y += dy;
        }
        return ans;
    }
};
