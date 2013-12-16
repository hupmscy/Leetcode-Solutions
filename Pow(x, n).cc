class Solution {
public:
    double pow(double x, int n) {
        if (fabs(x) < 1e-5)
            return 0;
        double tmp, res;
        bool sign = false;
        tmp = x;
        res = 1;
        long long ln = n;
        if (ln < 0)
        {
            sign = true;
            ln = -ln;
        }
        while (ln)
        {
            if (ln&1)
                res *= tmp;
            tmp *= tmp;
            ln >>= 1;
        }
        return sign ? 1/res : res;
    }
};
