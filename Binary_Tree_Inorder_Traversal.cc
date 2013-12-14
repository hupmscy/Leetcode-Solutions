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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            cur = cur->right;
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
        }
        return ans;
    }
};
