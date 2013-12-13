class Solution {
public:
    int singleNumber(int A[], int n) {
        int digit[32], res;
        memset(digit, 0, sizeof(digit));
        for (int i = 0; i < n; i++)
        {
            int tmp = A[i];
            for (int j = 0; j < 32; j++)
            {
                digit[j] += (tmp&1);
                tmp = (tmp>>1);
            }
        }
        res = 0;
        for (int i = 31; i >= 0; i--)
            res = ((res<<1) | (digit[i]%3));
        return res;
    }
};
