
int c[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
char alpha[10][5] = {"adf", "df", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


class Solution {
public:

    char tmp[1000];
    void dfs(int step, int n, char input[], vector<string> &ans)
    {
        if (step == n)
        {
            tmp[n] = 0;
            ans.push_back(tmp);
            return;
        }
        int v = input[step];
        for (int i = 0; i < c[v]; i++)
        {
            tmp[step] = alpha[v][i];
            dfs(step+1, n, input, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> ans;
        int n = digits.size();
        char input[n+10];
        for (int i = 0; i < n; i++)
            input[i] = digits[i]-48;
        dfs(0, n, input, ans);
        return ans;
    }
};
