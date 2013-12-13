/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {

        TreeNode *cur, *pre;
        stack<TreeNode*> st;
        vector<int> ans;
        if (root == NULL)
            return ans;
        cur = root;
        while (cur)
        {
            pre = cur;
            st.push(cur);
            cur = cur->left;
        }
        while (!st.empty())
        {
            cur = st.top();
            if (!cur->right || (pre && cur->right == pre))
            {
                ans.push_back(cur->val);
                st.pop();
                pre = cur;
            }
            else
            {
                pre = cur;
                cur = cur->right;
                while (cur)
                {
                    pre = cur;
                    st.push(cur);
                    cur = cur->left;
                }
            }
        }
        return ans;
    }
};
