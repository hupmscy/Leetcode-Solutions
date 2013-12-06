/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:

    struct hash_pair
    {
        int operator()(pair<double, double> p) const
        {
            return int(p.first+p.second);
        }
    };

    struct equal_pair
    {
        bool operator()(pair<double, double> p1, pair<double, double> p2) const
        {
            return fabs(p1.first-p2.first) < 1e-5 && fabs(p1.second - p2.second) < 1e-5;
        }
    };

    int maxPoints(vector<Point> &points) {
        if (points.size() == 0)
            return 0;
        int i, j, ans = 1, n = 0;
        int size = points.size();

        for (i = 0; i < size; i++)
        {
            int same = 1, maxv = 0;
            int x = points[i].x;
            int y = points[i].y;
            unordered_map<int, int> vertical;
            unordered_map<pair<double, double>, int, hash_pair, equal_pair> slope;
            for (j = i+1; j < size; j++)
            {
                if (points[j].x == x && points[j].y == y)
                {
                    same++;
                    continue;
                }
                if (x == points[j].x)
                    maxv = max(maxv, ++vertical[x]);
                else
                {

                    double k = double(y-points[j].y)/(x-points[j].x);
                    double b = y-k*x;
                    maxv = max(maxv, ++slope[make_pair(k, b)]);
                }
            }
            if (maxv + same > ans)
                ans = maxv+same;
        }
        return ans;
    }
};
