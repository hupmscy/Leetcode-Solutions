class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        for (int k = 0;;k++)
        {
            for (int i = 0; i < strs.size(); i++)
                if (strs[i].size() <= k || (i > 0 && strs[i][k] != strs[i-1][k]))
                {
                    if (k == 0)
                        return "";
                    return strs[i].substr(0, k);
                }
        }
    }
};
