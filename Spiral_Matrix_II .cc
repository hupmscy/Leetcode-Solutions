class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool visit[n+10][n+10];
        memset(visit, false, sizeof(visit));
        vector<vector<int> > ans;
        for (int i = 0; i < n; i++)
            ans.push_back(vector<int>(n));
        int x, y, dx, dy;
        x = y = 0;
        dx = 0;
        dy = 1;
        for (int i = 1; i <= n*n; i++)
        {
            ans[x][y] = i;
            visit[x][y] = true;
            if (dx == 0 && dy == 1 && ( y+1 >= n || visit[x][y+1]))
            {
                dx = 1;
                dy = 0;
            }
            else if (dx == 1 && dy == 0 && (x+1 >= n || visit[x+1][y]))
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
