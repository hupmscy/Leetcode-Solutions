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

    void depth(TreeNode *node, int dep)
    {
        if (!node->left && !node->right)
        {
            if (dep < ans)
                ans = dep;
            return;
        }

        if (node->left)
            depth(node->left,  dep+1);
        if (node->right)
            depth(node->right, dep+1);
    }

    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        ans = INT_MAX;
        depth(root, 1);
        return ans;
    }
};
