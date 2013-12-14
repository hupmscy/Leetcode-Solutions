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
    int search_tree(TreeNode *node)
    {
        int lv, rv;
        lv = rv = 0;
        if (node->left)
            lv = max(lv, search_tree(node->left));
        if (node->right)
            rv = max(rv, search_tree(node->right));
        if (lv+rv+node->val > ans)
            ans = lv+rv+node->val;
        return max(lv, rv)+node->val;
    }
    int maxPathSum(TreeNode *root) {
        if (!root)
            return 0;
        ans = INT_MIN;
        search_tree(root);
        return ans;
    }
};
