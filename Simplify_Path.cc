class Solution {
public:
    string simplifyPath(string path) {
        char str[5000];
        char *tok;
        string st[1000];
        int top = -1;
        strcpy(str, path.c_str());
        tok = strtok(str, "/");
        while (tok)
        {
            if (!strcmp(tok, ".."))
            {
                if (top != -1)
                    top--;
            }
            else if (strcmp(tok, "."))
                st[++top] = string(tok);
            tok = strtok(NULL, "/");
        }
        if (top == -1)
            return "/";
        string ans;
        for (int i = 0; i <= top; i++)
            ans = ans + "/" + st[i];
        return ans;
    }
};
