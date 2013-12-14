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

    bool ans;
    void find_path(TreeNode *node, int cur, int sum)
    {
        if (!node->left && !node->right)
        {
            if (cur+node->val == sum)
                ans = true;
            return;
        }
        if (node->left)
            find_path(node->left, cur+node->val, sum);
        if (node->right)
            find_path(node->right, cur+node->val, sum);
    }

    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
        {
        //    return sum ? false:true;
            return false;
        }
        ans = false;
        find_path(root, 0, sum);
        return ans;
    }
};
