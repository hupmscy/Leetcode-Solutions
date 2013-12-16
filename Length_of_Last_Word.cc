class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int start = 0;
        int end = strlen(s)-1;
        int i;
        while (start <= end && s[start] == ' ')
            start++;
        while (start <= end && s[end] == ' ')
            end--;
        if (start > end)
            return 0;
        i = end;
        while (i >= start && s[i] != ' ')i--;
        if (i < start)
            return end-start+1;
        return end-i;
    }
};
