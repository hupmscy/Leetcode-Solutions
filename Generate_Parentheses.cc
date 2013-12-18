class Solution {
public:

    char tmp[100];

    void dfs(int step, int n, int left, int right, vector<string> &ans)
    {
        if (step == n)
        {
            if (left == n/2)
            {
                tmp[step] = 0;
                ans.push_back(tmp);
            }
            return;
        }
        if (left > n/2 || left < right)
            return;
        tmp[step] = '(';
        dfs(step+1, n, left+1, right, ans);
        tmp[step] = ')';
        dfs(step+1, n, left, right+1, ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if (n == 0)
            return ans;
        dfs(0, 2*n, 0, 0, ans);
        return ans;
    }
};
