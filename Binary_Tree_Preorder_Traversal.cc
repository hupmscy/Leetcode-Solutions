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
    vector<int> preorderTraversal(TreeNode *root) {

        stack<TreeNode*> st;
        TreeNode* cur = root;
        vector<int> ans;
        if (!root)
            return ans;
        st.push(root);
        while (!st.empty())
        {
            cur = st.top();
            st.pop();
            while (cur)
            {
                ans.push_back(cur->val);
                if (cur->right)
                    st.push(cur->right);
                cur = cur->left;
            }
        }
        return ans;
    }
};
