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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (!root)
            return ans;
        queue<pair<TreeNode*, int> > q;
        pair<TreeNode*, int> tmp;
        vector<int> nodes;
        int lev, cur_lev = 1;
        TreeNode* cur;
        q.push(make_pair(root, 1));
        while(!q.empty())
        {
            tmp = q.front();
            q.pop();
            cur = tmp.first;
            lev = tmp.second;
            if (cur_lev < lev)
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
        for (int i = 1; i < ans.size(); i+=2)
            reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};
