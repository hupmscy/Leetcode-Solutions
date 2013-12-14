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

    bool balanced;

    int height(TreeNode *node)
    {
        if (!node)
            return 0;
        int hl = height(node->left);
        int hr = height(node->right);
        if (abs(hl-hr) > 1)
            balanced = false;
        return max(hl, hr)+1;
    }

    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        balanced = true;
        height(root);
        return balanced;
    }
};
