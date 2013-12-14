class Solution {
public:

    inline bool not_alphanumic(string &s, int i)
    {
        char ch = s[i];
        return !((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch >= 48 && ch <= 57));
    }

    bool isPalindrome(string s) {
       if (s.size() == 0)
        return true;
        int len = s.size();
        int i = 0, j = len-1;
        while (i < j)
        {
            while (i < j && not_alphanumic(s, i))i++;
            while (i < j && not_alphanumic(s, j))j--;
            if ((s[i] >= 48 && s[i] <= 57 && s[i] != s[j]) || (!(s[i] == s[j] || abs(s[i]-s[j]) == 32)))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
