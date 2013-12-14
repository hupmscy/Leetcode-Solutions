class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0)
            return 0;
        int i;
        for (i = 1; i < triangle.size(); i++)
        {
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for (int j = 1; j < i; j++)
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
        }
        int ans = INT_MAX;
        int n = triangle.size();
        for (i = 0; i < n; i++)
            if (ans > triangle[n-1][i])
                ans = triangle[n-1][i];
        return ans;
    }
};
