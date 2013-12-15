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
    ListNode *partition(ListNode *head, int x) {
        if (!head)
            return head;
        ListNode *head1, *head2, *cur1, *cur2, *cur;
        cur = head;
        head1 = head2 = cur1 = cur2 = NULL;
        while (cur)
        {
            if (cur->val < x)
            {
                if (!head1)
                    head1 = cur1 = cur;
                else
                {
                    cur1->next = cur;
                    cur1 = cur1->next;
                }
            }
            else
            {
                if (!head2)
                    head2 = cur2 = cur;
                else
                {
                    cur2->next = cur;
                    cur2 = cur2->next;
                }
            }
            cur = cur->next;
        }
        if (!head1)
            return head2;
        else if (!head2)
            return head1;

        cur1->next = head2;
        cur2->next = NULL;
        return head1;
    }
};
