class Solution {
public:

    void init_next(char *needle, int len, int next[])
    {
        int j = 0, k = -1;
        next[0] = -1;
        while (j < len)
        {
            if (k == -1 || needle[j] == needle[k])
            {
                k++;
                j++;
                if (needle[j] != needle[k])
                    next[j] = k;
                else
                    next[j] = next[k];
            }
            else
                k = next[k];
        }
    }

    char *strStr(char *haystack, char *needle) {
            if (!haystack || !needle)
                return haystack;
            int len = strlen(needle);
            int len1 = strlen(haystack);
            int next[len+10];
            int i, j;
            memset(next, 0, sizeof(next));
            init_next(needle, len, next);
            i = j = 0;
            while (i < len1)
            {
                if (haystack[i] == needle[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    if (j == len)
                        return haystack+i-j;
                    if (next[j] != -1)
                        j = next[j];
                    else
                    {
                        j = 0;
                        i++;
                    }
                }
            }
            if (j == len)
                return haystack+i-j;
            else
                return NULL;
    }
};
