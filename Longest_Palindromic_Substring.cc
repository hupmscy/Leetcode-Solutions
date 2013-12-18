class Solution {
public:
    string longestPalindrome(string s) {
         if (s.size() == 0)
            return 0;
        int len = s.size();
        int p[2*len+10];
        memset(p, 0, sizeof(p));
        int i, j, id, rightlen, len1;
        char t[2*len+10], output[len+2];
        memset(t, 0, sizeof(t));
        t[0] = -1;
        for (i = 0; i < len; i++)
        {
            t[2*i+1] = 1;
            t[2*i+2] = s[i];
        }
        t[2*len+1] = 1;
        t[2*len+2] = 2;
        len1 = 2*len+2;
        p[0] = p[1] = 1;
        id = 1;
        rightlen = 1;
        for (i = 2; i < len1; i++)
        {
            j = 2*id -i;
            p[i] = p[j] < id+rightlen-i ? p[j] : id+rightlen-i;
            while (t[i-p[i]] == t[i+p[i]])p[i]++;
            if (i+p[i] > id + rightlen)
            {
                id = i;
                rightlen = p[i];
            }
        }
        int ans = 0;
        for (i = 1; i < len1; i++)
            if (ans < p[i])
            {
                ans = p[i];
                int c = 0;
                for (j = i-p[i]+1; j < i+p[i]; j++)
                    if (t[j] != 1)
                        output[c++] = t[j];
                output[c] = 0;
            }
        return string(output);
    }
};
