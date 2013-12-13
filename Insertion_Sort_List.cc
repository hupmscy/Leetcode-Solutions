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
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *cur, *tmp, *pre, *tmp_pre, *p;
        pre = head;
        cur = head->next;
        while (cur)
        {
            tmp = head;
            tmp_pre = NULL;
            while (tmp != cur && tmp->val <= cur->val)
            {
                tmp_pre = tmp;
                tmp = tmp->next;
            }
            if (tmp != cur)
            {
                p = cur->next;
                pre->next = cur->next;
                if (tmp_pre)
                    tmp_pre->next = cur;
                cur->next = tmp;
                if (head == tmp)
                    head = cur;
                cur = p;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }

        }
        return head;
    }
};
