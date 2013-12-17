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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1)return head;
        ListNode *pre_end, *cur_start, *next_start, *cur, *cur_end, *pre, *next, *res_head;
        res_head = pre_end = NULL;
        int i;
        cur_start = head;
        while (cur_start)
        {
            cur = cur_start;
            i = 1;
            while (cur && i < k)
            {
                i++;
                cur = cur->next;
            }
            if (cur == NULL)
                break;
            cur_end = cur;
            next_start = cur->next;
            cur = cur_start;
            pre = NULL;
            while (cur_end != cur)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            cur->next = pre;
            if (!res_head)
                res_head = cur_end;
            else
                pre_end->next = cur_end;
            pre_end = cur_start;
            cur_start->next = next_start;
            cur_start = next_start;
        }
        if (res_head == NULL)
            res_head = head;
        return res_head;
    }
};
