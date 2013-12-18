\class Solution {
public:
    int atoi(const char *str) {
        if (!str)
            return 0;
        int start, end;
        bool sign = false;
        start = 0;
        end = strlen(str)-1;

        while (start <= end && str[start] == ' ')start++;
        while (start <= end && str[end] == ' ')end--;

        if (start > end)
            return 0;

        if (str[start] == '+' || str[start] == '-')
        {
            sign = (str[start] == '-' ? true : false);
            start++;
        }
        if (start > end)
            return 0;
        long long ans = 0;
        for (int i = start; i <= end && str[i] >= '0' && str[i] <= '9'; i++)
            ans = ans*10 + str[i]-48;
        if (!sign)
            return ans > INT_MAX ? INT_MAX: ans;
        else
            return -ans < INT_MIN ? INT_MIN : -ans;
    }
};
