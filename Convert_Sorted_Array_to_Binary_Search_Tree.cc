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

    TreeNode* build_tree(vector<int> &num, int l, int r)
    {
        int mid = (l+r)/2;
        TreeNode *node = new TreeNode(num[mid]);
        if (l < mid)
            node->left = build_tree(num, l, mid-1);
        if (mid < r)
            node->right = build_tree(num, mid+1, r);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
            return NULL;
        return build_tree(num, 0, num.size()-1);
    }
};
