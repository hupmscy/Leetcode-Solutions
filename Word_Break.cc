class Solution {
public:
    #define SIZE 5000
    bool dp[SIZE];
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0 || dict.size() == 0)
            return false;
        int max_len = -1;
        int min_len = INT_MAX;
        memset(dp, false, sizeof(dp));
        for (unordered_set<string>::iterator iter = dict.begin(); iter != dict.end(); iter++)
        {
            int size = (*iter).size();
            if (size > max_len)
                max_len = size;
            if (size < min_len)
                min_len = size;
        }
        dp[0] = true;
        for (int i = min_len; i <= s.size(); i++)
        {
            int bound = i-max_len >= 0 ? i-max_len:0;
            for (int j = i-min_len; j >= bound; j--)
                if (dict.find(s.substr(j, i-j)) != dict.end() && dp[j])
                {
                    dp[i] = true;
                    break;
                }
        }
        return dp[s.size()];
    }
};
