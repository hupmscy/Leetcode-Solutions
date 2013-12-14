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

    TreeNode *pre;

    bool valid(TreeNode *cur)
    {
        if (cur->left)
        {
            if (!valid(cur->left))
                return false;
        }
        if (pre)
        {
            if (pre->val >= cur->val)
                return false;
        }
        pre = cur;
        if (cur->right)
            return valid(cur->right);
        return true;
    }

    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        pre = NULL;
        return valid(root);
    }
};
