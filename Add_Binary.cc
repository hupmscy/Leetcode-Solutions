class Solution {
public:

    void trans(char a[], int len)
    {
        for (int i = 0; i < len; i++)
            a[i] -= 48;
        for (int i = 0; i < len/2; i++)
            swap(a[i], a[len-i-1]);
    }

    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();
        int len = max(len1, len2);
        char va[len+10], vb[len+10];
        int c, i;
        memset(va, 0, sizeof(va));
        memset(vb, 0, sizeof(vb));
        strcpy(va, a.c_str());
        strcpy(vb, b.c_str());
        trans(va, len1);
        trans(vb, len2);
        for (i = c = 0; i < len; i++)
        {
            int v = va[i]+vb[i]+c;
            va[i] = v % 2;
            c = v/2;
        }
        if (c)
        {
            va[len] = c;
            len++;
        }
        for (i = 0; i < len; i++)
            va[i] += 48;
        for (i = 0; i < len/2; i++)
            swap(va[i], va[len-i-1]);
        va[len] = 0;
        return string(va);
    }
};
