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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return head;
        int i = 0, j;
        ListNode *cur = head, *pre;
        while (cur)
        {
            i++;
            cur = cur->next;
        }
        int k = i-n;
        cur = head;
        j = 0;
        pre = NULL;
        while (j < k)
        {
            j++;
            pre = cur;
            cur = cur->next;
        }
        if (cur == head)
            return head->next;
        else
            pre->next = cur->next;
        return head;
    }
};
