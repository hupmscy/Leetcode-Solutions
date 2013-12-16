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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head)
            return head;
        ListNode *cur = head, *tail, *pre;
        int n = 0, i = 0;
        while (cur)
        {
            n++;
            tail = cur;
            cur = cur->next;
        }
        k = k % n;
        if (k == 0)
            return head;

        pre = NULL;
        cur = head;
        while (i < n-k)
        {
            i++;
            pre = cur;
            cur = cur->next;
        }
        tail->next = head;
        head = cur;
        pre->next = NULL;
        return head;
    }
};
