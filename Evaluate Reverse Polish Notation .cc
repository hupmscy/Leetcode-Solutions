class Solution {
public:
    int operate(int num1, int num2, char ch)
    {
        if (ch == '+')
            return num1+num2;
        else if (ch == '-')
            return num1-num2;
        else if (ch == '*')
            return num1*num2;
        else
            return num1/num2;
    }
    int to_num(string &num)
    {
        int res = 0, i = 0;
        bool neg = false;
        if (num[0] == '-')
        {
            i++;
            neg = true;
        }
        for (; i < num.size(); i++)
            res = res*10 + (num[i]-48);
        return neg ? -res : res;
    }

    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        if (tokens.size() == 0)
            return 0;
        for (int i = 0; i < tokens.size(); i++)
        {
            char ch = tokens[i][0];
            if ((ch < 48 || ch > 57) && tokens[i].size() == 1)
            {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                st.push(operate(num1, num2, tokens[i][0]));
            }
            else
                st.push(to_num(tokens[i]));
        }
        return st.top();
    }
};
