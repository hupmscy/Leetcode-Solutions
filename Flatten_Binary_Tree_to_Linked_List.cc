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

    void link(TreeNode *post, TreeNode *cur)
    {
        if (!cur->left && !cur->right)
        {
            cur->right = post;
            return;
        }
        if (!cur->left)
        {
            link(post, cur->right);
            return;
        }
        TreeNode *tmp = cur->right;
        cur->right = cur->left;
        cur->left = NULL;
        link(tmp?tmp:post, cur->right);
        if (tmp)
            link(post, tmp);
    }

    void flatten(TreeNode *root) {

        if (!root)
            return;

        link(NULL, root);
    }
};
