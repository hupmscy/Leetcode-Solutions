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
    TreeNode *p1, *p2, *pre;
    void search(TreeNode *cur)
    {
        if (cur->left)
            search(cur->left);

        if (pre)
        {
            if (!p1 && pre->val > cur->val)
                p1 = pre;
            if (p1 && pre->val > cur->val)
                p2 = cur;
        }
        pre = cur;
        if (cur->right)
            search(cur->right);
    }
    void recoverTree(TreeNode *root) {
        pre = p1 = p2 = NULL;
        search(root);
        int v = p1->val;
        p1->val = p2->val;
        p2->val = v;
    }
};
