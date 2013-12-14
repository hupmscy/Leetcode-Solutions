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

    TreeNode* build_tree(int l1, int l2, int r2, vector<int> &pre, vector<int> &in)
    {
        int i;
        for (i = l2; i <= r2; i++)
            if (pre[l1] == in[i])
                break;
        TreeNode *node = new TreeNode(pre[l1]);
        if (i > l2)
            node->left = build_tree(l1+1, l2, i-1, pre, in);
        if (i < r2)
            node->right = build_tree(l1+i-l2+1, i+1, r2, pre, in);
        return node;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0)
            return NULL;
        return build_tree(0, 0, inorder.size()-1, preorder, inorder);
    }
};
