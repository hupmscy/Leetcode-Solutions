/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        queue<pair<TreeLinkNode*, int> > q;
        TreeLinkNode *cur, *pre;
        int lev = 1, cur_lev = 1;
        pair<TreeLinkNode*, int> tmp;
        cur = pre = NULL;
        q.push(make_pair(root, 1));

        while (!q.empty())
        {
            tmp = q.front();
            q.pop();
            cur = tmp.first;
            lev = tmp.second;
            if (lev > cur_lev)
            {
                cur_lev++;
                pre = cur;
            }
            else
            {
                if (pre)
                    pre->next = cur;
                pre = cur;
            }
            if (cur->left)
                q.push(make_pair(cur->left, lev+1));
            if (cur->right)
                q.push(make_pair(cur->right, lev+1));
        }
    }
};
