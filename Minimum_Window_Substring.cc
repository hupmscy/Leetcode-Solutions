class Solution {
public:
    string minWindow(string S, string T) {
        int freq[300], cur[300], c, i, j, tlen, slen, ans, ansl, ansr;
        memset(freq, 0, sizeof(freq));
        memset(cur, 0, sizeof(cur));
        tlen = T.size();
        slen = S.size();
        for (i = 0; i < T.size(); i++)
            freq[T[i]]++;
        i = j = c = 0;
        ans = INT_MAX;
        while (i < slen)
        {
            while (i < slen && c < tlen)
            {
                char ch = S[i];
                cur[ch]++;
                if (freq[ch])
                {
                    if (cur[ch] <= freq[ch])
                        c++;
                    if (c == tlen)
                        break;
                }
                i++;
            }
            while (j <= i && c == tlen)
            {
                if (i-j+1 < ans)
                {
                    ans = i-j+1;
                    ansl = j;
                    ansr = i;
                }
                char ch = S[j];
                cur[ch]--;
                if (cur[ch] < freq[ch])
                    c--;
                j++;
            }
            i++;
        }
        if (ans == INT_MAX)
            return "";
        return S.substr(ansl, ansr-ansl+1);
    }
};
