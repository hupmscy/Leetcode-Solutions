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
        ListNode *res, *pre, *cur, *tmp;
        res = pre = NULL;
        cur = head;
        while (cur)
        {
            tmp = cur->next;
            while (tmp && cur->val == tmp->val)tmp = tmp->next;
            if (tmp == cur->next)
            {
                if (!res)
                    res = pre = cur;
                else
                {
                    pre->next =  cur;
                    pre = pre->next;
                }
            }
            cur = tmp;
        }
        if (res)
            pre->next = NULL;
        return res;
    }
};
