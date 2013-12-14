/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

    TreeNode *build_tree(ListNode *l, ListNode *r, ListNode *bound)
    {
        ListNode *slow, *fast, *pre;
        pre = NULL;
        slow = fast = l;
        while (fast->next != bound && fast->next->next != bound)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        if (pre)
            node->left = build_tree(l, pre, slow);
        if (slow != r)
            node->right = build_tree(slow->next, r, r->next);
        return node;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        ListNode *fast;
        fast = head;
        while (fast->next && fast->next->next)
            fast = fast->next->next;
        if (fast->next)
            fast = fast->next;
        return build_tree(head, fast, fast->next);
    }
};
