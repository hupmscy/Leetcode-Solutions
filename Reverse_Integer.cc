class Solution {
public:
    int reverse(int x) {
        long long a = x, b = 0;
        bool sign = a < 0 ? true:false;
        a = abs(a);
        while (a)
        {
            b = b*10 + a%10;
            a/=10;
        }
        return sign ? -b : b;
    }
};
