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

    TreeNode *build_tree(int r1, int l2, int r2, vector<int> &post, vector<int> &in)
    {
        int i;
        for (i = l2; i <= r2; i++)
            if (post[r1] == in[i])
                break;
        TreeNode *node = new TreeNode(post[r1]);
        if (i < r2)
            node->right = build_tree(r1-1, i+1, r2, post, in);
        if (i > l2)
            node->left = build_tree(r1-(r2-i+1), l2, i-1, post, in);
        return node;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0)
            return NULL;
        return build_tree(postorder.size()-1, 0, inorder.size()-1, postorder, inorder);
    }
};
