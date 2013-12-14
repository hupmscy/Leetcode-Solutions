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

    void search(TreeNode *node, int dep)
    {
        if (!node->left && !node->right)
        {
            if (dep+1 > ans)
                ans = dep+1;
            return;
        }
        if (node->left)
            search(node->left, dep+1);
        if (node->right)
            search(node->right, dep+1);
    }

    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        ans = 0;
        search(root, 0);
        return ans;
    }
};
