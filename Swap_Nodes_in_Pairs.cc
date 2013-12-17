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
    ListNode *swapPairs(ListNode *head) {
        if (!head || head->next == NULL)
            return head;
        ListNode *cur, *pre, *next, *res, *pre_end;
        cur = head;
        pre_end = res = NULL;
        while (cur)
        {
            if (cur->next == NULL)
                break;
            pre = cur;
            next = cur->next->next;
            cur = cur->next;
            if (res == NULL)
                res = cur;
            else
                pre_end->next = cur;
            pre_end = pre;
            cur->next = pre;
            pre->next = next;
            cur = next;
        }
        return res;
    }
};
