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
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next)
            return;
        ListNode *fast, *slow, *pre, *cur, *next, *tmp, *tmp1;
        fast = slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        tmp = slow;
        slow = slow->next;
        tmp->next = NULL;
        cur = slow;
        pre = NULL;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        cur = head;
        while (pre)
        {
            tmp = cur->next;
            cur->next = pre;
            tmp1 = pre->next;
            pre->next = tmp;
            pre = tmp1;
            cur = tmp;
        }

    }
};
