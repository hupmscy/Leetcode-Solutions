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

    bool is_symetric(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 || !node2)
        {
            return !node1 && !node2;
        }
        return node1->val == node2->val && is_symetric(node1->left, node2->right) && is_symetric(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return is_symetric(root, root);
    }
};
