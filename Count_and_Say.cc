class Solution {
public:
    #define SIZE 5000
    string countAndSay(int n) {
        char str[2][SIZE];
        memset(str, 0, sizeof(str));
        char *cur, *next;
        int cur_len, next_len, i, j, k, l;
        cur = str[0];
        next = str[1];
        next[0] = 1;
        next_len = 1;
        for (int i = 2; i <= n; i++)
        {
            memcpy(cur, next, sizeof(char)*SIZE);
            cur_len = next_len;
            next_len = 0;
            j = 0;
            while (j < cur_len)
            {
                k = j+1;
                while (k < cur_len && cur[k] == cur[k-1])k++;
                int tmp = k-j;
                int digit = 0;
                while (tmp)
                {
                    digit++;
                    tmp/=10;
                }
                tmp = k-j;
                for (l = next_len+digit-1; l >= next_len; l--)
                {
                    next[l] = tmp%10;
                    tmp /= 10;
                }
                next_len += digit;
                next[next_len++] = cur[j];
                j = k;
            }
        }
        for (int i = 0; i < next_len; i++)
            next[i] += 48;
        next[next_len] = 0;
        return string(next);
    }
};
