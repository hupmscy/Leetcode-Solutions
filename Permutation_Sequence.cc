class Solution {
public:
    string getPermutation(int n, int k) {
        bool visit[20];
        int seq[20];
        int fact[20], i, j;
        string ans = "";
        memset(visit, false, sizeof(visit));
        fact[0] = 1;
        for (i = 1; i <= 10; i++)
            fact[i] = fact[i-1]*i;
        k--;
        for (i = n; i >= 1; i--)
        {
            seq[n-i] = k/fact[i-1];
            k -= seq[n-i]*fact[i-1];
        }
        for (i = 0; i < n; i++)
        {
            int c = -1;
            for (j = 1; j <= n; j++)
                if (!visit[j])
                {
                    c++;
                    if (c == seq[i])
                    {
                        ans = ans + char(j+48);
                        visit[j] = true;
                        break;
                    }
                }
        }
        return ans;
    }
};
