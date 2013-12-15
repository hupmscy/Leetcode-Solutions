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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (!head || m == n)
            return head;
        ListNode *cur, *pre, *next, *pre1, *tmp1;
        int i = 1;
        pre = NULL;
        cur = head;
        while (i < m)
        {
            pre = cur;
            cur = cur->next;
            i++;
        }

        pre1 = NULL;
        while (i <= n)
        {
            next = cur->next;
            cur->next = pre1;
            pre1 = cur;
            cur = next;
            i++;
        }
        if (!pre)
        {
            tmp1 = head;
            head = pre1;
        }
        else
        {
            tmp1 = pre->next;
            pre->next = pre1;
        }
        tmp1->next = next;
        return head;
    }
};
