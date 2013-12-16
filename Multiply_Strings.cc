class Solution {
public:

    void trans(char a[], int len)
    {
        for (int i = 0; i < len; i++)
            a[i] -= 48;
        for (int i = 0; i < len/2; i++)
            swap(a[i], a[len-1-i]);
    }

    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len = max(len1, len2);
        int i, j, len3, carry, v;
        char a[len+10];
        char b[len+10];
        char c[2*len+10];
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
        strcpy(a, num1.c_str());
        strcpy(b, num2.c_str());
        trans(a, len1);
        trans(b, len2);
        for (i = 0; i < len1; i++)
        {
            int d = a[i];
            carry = 0;
            for (j = 0; j < len2; j++)
            {
                v = d*b[j] + c[i+j] + carry;
                c[i+j] = v%10;
                carry = v/10;
            }
            c[i+j] = carry;
        }
        if (carry)
            len3 = len1+len2;
        else
            len3 = len1+len2-1;
        while (len3 > 1 && c[len3-1] == 0)
            len3--;
        for (i = 0; i < len3/2; i++)
            swap(c[i], c[len3-i-1]);
        for (i = 0; i < len3; i++)
            c[i] += 48;
        c[len3] = 0;
        return string(c);
    }
};
