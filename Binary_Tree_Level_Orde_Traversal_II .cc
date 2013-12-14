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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > ans;
        if (!root)
            return ans;

        queue<pair<TreeNode*, int> > q;
        vector<int> nodes;
        pair<TreeNode*, int> tmp;
        TreeNode* cur;
        int lev, cur_lev = 1;
        q.push(make_pair(root, 1));
        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            cur = tmp.first;
            lev = tmp.second;
            if (lev > cur_lev)
            {
                ans.push_back(nodes);
                nodes.clear();
                nodes.push_back(cur->val);
                cur_lev++;
            }
            else
                nodes.push_back(cur->val);
            if (cur->left)
                q.push(make_pair(cur->left, lev+1));
            if (cur->right)
                q.push(make_pair(cur->right, lev+1));
        }
        ans.push_back(nodes);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
