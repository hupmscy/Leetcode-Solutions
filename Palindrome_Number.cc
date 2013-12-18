class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long long a = x, b = 0, tmp = a;
        while (tmp)
        {
            b = b*10 + tmp%10;
            tmp/=10;
        }
        return a==b;
    }
};
