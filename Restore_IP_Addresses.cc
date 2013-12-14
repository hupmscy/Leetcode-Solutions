class Solution {
public:
    char str[400];
    void dfs(int rpos, int wpos, int step, vector<string> &ans, string &s)
    {
        if (step == 4)
        {
            if (rpos == s.size())
            {
                str[wpos-1] = 0;
                ans.push_back(string(str));
            }
            return;
        }
        if (rpos >= s.size())
            return;
        int v = 0;
        for (int i = rpos; i < s.size(); i++)
        {
            v = v*10 + s[i]-48;
            str[wpos++] = s[i];
            if (v <= 255)
            {
                str[wpos] = '.';
                dfs(i+1, wpos+1, step+1, ans, s);
            }
            else
                break;
            if (v == 0)
                break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        dfs(0, 0, 0, ans, s);
        return ans;
    }
};
