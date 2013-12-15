/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        ListNode *cur, *tmp;
        cur = head;
        while (cur)
        {
            tmp = cur->next;
            while (tmp && cur->val == tmp->val)tmp = tmp->next;
            cur->next = tmp;
            cur = tmp;
        }
        return head;
    }
};
