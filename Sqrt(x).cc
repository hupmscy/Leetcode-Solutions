class Solution {
public:
    int sqrt(int x) {
        double cur, next, res = x;
        next = 1;
        do
        {
            cur = next;
            next = (cur+res/cur)*.5;
        }while (fabs(next*next-res) > 1e-4);
        return int(next);
    }
};
