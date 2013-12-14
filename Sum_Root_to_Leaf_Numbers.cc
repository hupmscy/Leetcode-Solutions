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
    int ans;

    void traverse(TreeNode *node, int v)
    {
        if (!node->left && !node->right)
            ans += (v*10 + node->val);
        if (node->left)
            traverse(node->left, v*10+node->val);
        if (node->right)
            traverse(node->right, v*10+node->val);
    }

    int sumNumbers(TreeNode *root) {
        if (!root)
            return 0;
        ans = 0;
        traverse(root, 0);
        return ans;
    }
};
