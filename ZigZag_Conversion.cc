class Solution {
public:
    string convert(string s, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 1)
            return s;
        int len = s.size();
        char out[len+10];
        int k = 0, pos = 0;
        while ((2*n-2)*k < len)
        {
            out[pos++] = s[(2*n-2)*k];
            k++;
        }
        for (int i = 1; i < n-1; i++)
        {
            if (i < len)
                out[pos++] = s[i];
            else
                break;
            for (int j = 1; j <= k; j++)
            {
                int off = (2*n-2)*j;
                if (off-i < len)
                    out[pos++] = s[off-i];
                if (off+i < len)
                    out[pos++] = s[off+i];
            }
        }
        k = 0;
        while ((2*n-2)*k+n-1 < len)
        {
            out[pos++] = s[(2*n-2)*k+n-1];
            k++;
        }
        out[pos] = 0;
        return string(out);
    }
};
