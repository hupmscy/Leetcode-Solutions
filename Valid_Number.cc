class Solution {
public:
    bool isNumber(const char *s) {
        int start, end, e, dot, epos, dotpos[3], i, j;
        start = e = dot = 0;
        end = strlen(s)-1;
        while (start <= end && s[start] == ' ')start++;
        if (start > end)
            return false;
        while (start <= end && s[end] == ' ')end--;
        if (start > end)
            return false;
        if (s[start] == '+' || s[start] == '-')
            start++;
        for (i = start; i <= end; i++)
        {
            if (!((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == 'e'))
            {
                if ((s[i] == '+' || s[i] == '-') && s[i-1] == 'e')
                    continue;
                return false;
            }
            if (s[i] == 'e')
            {
                e++;
                epos = i;
            }
            if (s[i] == '.')
            {
                dotpos[dot++] = i;
                if (dot > 2)
                    return false;
            }
        }
        if (e > 1 || (e == 0 && dot > 1))
            return false;
        if (dot == 2)
        {
            if (!(dotpos[0] < epos && dotpos[1] > epos))
                return false;
        }
        if (e == 1)
        {
            for (i = start; i < epos; i++)
                if (s[i] >= '0' && s[i] <= '9')
                    break;
            if (i == epos)
                return false;
            bool has_num = false;
            for (i = epos+1; i <= end; i++)
            {
                if (s[i] >= '0' && s[i] <= '9')
                    has_num = true;
                if (s[i] == '.')
                    return false;
            }
            if (!has_num)
                return false;
        }
        if (dot)
        {
            bool mark = false;
            for (i = start; i < dotpos[0]; i++)
                if (s[i] >= '0' && s[i] <= '9')
                {
                    mark = true;
                    break;
                }
            for (i = dotpos[0]+1; i <= end; i++)
                if (s[i] >= '0' && s[i] <= '9')
                {
                    mark = true;
                    break;
                }
            if (!mark)
                return false;
        }
        return true;
    }
};
