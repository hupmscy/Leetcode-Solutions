class Solution {
public:
    int divide(int a, int b) {
        long long na = a;
        long long nb = b;
        bool sign =  na*nb > 0 ? false : true;
        na = abs(na);
        nb = abs(nb);
        long long tmp, res, cur, tmp1;
        res = 0;
        cur = 0;
        while (cur+nb <= na)
        {
            tmp1 = 1;
            tmp = nb;
            while (cur+tmp <= na)
            {
                cur += tmp;
                res += tmp1;
                tmp1 += tmp1;
                tmp += tmp;
            }
        }
        return sign ? -res : res;
    }
};
