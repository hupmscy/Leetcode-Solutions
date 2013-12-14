class Solution {
public:
    #define SIZE 5000
    char str[SIZE];
    bool is_palindrome(char str[], int l, int r)
    {
        for (int i = l; i <= (l+r)/2; i++)
            if (str[i] != str[r-i+l])
                return false;
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans[SIZE];
        if (s.size() == 0)
            return ans[0];
        strcpy(str, s.c_str());
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = i-1; j > 0; j--)
            {
                if (is_palindrome(str, j, i-1) && ans[j].size() > 0)
                {
                    for (int k = 0; k < ans[j].size(); k++)
                    {
                        vector<string> tmp = ans[j][k];
                        tmp.push_back(string(str+j, i-j));
                        ans[i].push_back(tmp);
                    }
                }
            }
            if (is_palindrome(str, 0, i-1))
            {
                vector<string> tmp;
                tmp.push_back(string(str, i));
                ans[i].push_back(tmp);
            }
        }
        return ans[s.size()];
    }
};
