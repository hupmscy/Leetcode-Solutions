class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (ch == '(')
                st.push(i);
            else
            {
                if (!st.empty() && s[st.top()] == '(')
                {
                    st.pop();
                    int l = st.empty() ? -1 : st.top();
                    if (i-l > ans)
                        ans = i-l;
                }
                else
                    st.push(i);
            }
        }
        return ans;
    }
};
