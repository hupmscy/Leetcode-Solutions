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
    int path[1000];
    void find_path(TreeNode *node, int cur, int sum, vector<vector<int> > &ans, int dep)
    {
        if (!node->left && !node->right)
        {
            if (cur+node->val == sum)
            {
                vector<int> tmp;
                for (int i = 0; i < dep; i++)
                    tmp.push_back(path[i]);
                tmp.push_back(node->val);
                ans.push_back(tmp);
            }
            return;
        }
        path[dep] = node->val;
        if (node->left)
            find_path(node->left, cur+node->val, sum, ans, dep+1);
        if (node->right)
            find_path(node->right, cur+node->val, sum, ans, dep+1);
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ans;
        if (!root)
        {
            return ans;
        }
        find_path(root, 0, sum, ans, 0);
    }
};
