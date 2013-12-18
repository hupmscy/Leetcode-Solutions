class Solution {
public:

    int trans(char ch)
    {
        switch(ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
    }

    int romanToInt(string s) {
        if (s.size() == 0)
            return 0;
        int i = 0, n = s.size(), ans = 0;
        while (i < n)
        {
            if (i < n-1 && trans(s[i]) < trans(s[i+1]))
            {
                ans += trans(s[i+1]) -trans(s[i]);
                i+=2;
            }
            else
            {
                ans += trans(s[i]);
                i++;
            }
        }
        return ans;
    }
};
