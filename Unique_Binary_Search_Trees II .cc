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
    int c;

    void copy_node(TreeNode *node, TreeNode *node1)
    {
        if (node->left)
        {
            TreeNode* left_node = new TreeNode(0);
            node1->left = left_node;
            copy_node(node->left, node1->left);
        }
        if (node->right)
        {
            TreeNode *right_node = new TreeNode(0);
            node1->right = right_node;
            copy_node(node->right, node1->right);
        }
    }

    TreeNode* copy_tree(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        TreeNode* root_copy = new TreeNode(0);
        copy_node(root, root_copy);
        return root_copy;
    }

    vector<TreeNode *> generateTrees(int n) {
        TreeNode *root = new TreeNode(0);
        vector<TreeNode*> ans[20];
        ans[1].push_back(root);
        ans[0].push_back(NULL);
        if (n == 0)
            return ans[0];

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j <= i-1; j++)
            {
                for (int k = 0; k < ans[j].size(); k++)
                for (int l = 0; l < ans[i-j-1].size(); l++)
                {
                    TreeNode *node = new TreeNode(0);
                    TreeNode *left_copy = copy_tree(ans[j][k]);
                    TreeNode *right_copy = copy_tree(ans[i-j-1][l]);
                    node->left = left_copy;
                    node->right = right_copy;
                    ans[i].push_back(node);
                }
            }
        }
        for (int i = 0; i < ans[n].size(); i++)
        {
            c = 1;
            inorder(ans[n][i]);
        }
        return ans[n];
    }

    void inorder(TreeNode *cur)
    {
        if (cur->left)
            inorder(cur->left);
        cur->val = c++;
        if (cur->right)
            inorder(cur->right);
    }
};
