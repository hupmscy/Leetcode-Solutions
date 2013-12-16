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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2)
            return NULL;
        else if (!l1)
            return l2;
        else if (!l2)
            return l1;

        ListNode *head, *cur1, *cur2, *cur;
        head = cur = NULL;
        cur1 = l1;
        cur2 = l2;
        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                if (!head)
                    head = cur = cur1;
                else
                {
                    cur->next = cur1;
                    cur = cur->next;
                }
                cur1 = cur1->next;
            }
            else
            {
                if (!head)
                    head = cur = cur2;
                else
                {
                    cur->next = cur2;
                    cur = cur->next;
                }
                cur2 = cur2->next;
            }
        }
        if (cur1)
            cur->next = cur1;
        else
            cur->next = cur2;
        return head;
    }
};
