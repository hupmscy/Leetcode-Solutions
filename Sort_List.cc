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

    ListNode* merge_sort(ListNode *start, ListNode *end, int len)
    {
        if (len == 1)
            return start;
        int mid, i;
        ListNode *cur, *pre, *l1, *l2, *head;
        mid = len/2;
        i = 0;
        cur = start;
        while (i < mid)
        {
            i++;
            pre = cur;
            cur = cur->next;
        }
        pre->next = NULL;
        end->next = NULL;
        l1 = merge_sort(start, pre, mid);
        l2 = merge_sort(cur, end, len-mid);
        head = cur = NULL;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                if (!head)
                    head = cur = l1;
                else
                {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            }
            else
            {
                if (!head)
                    head = cur = l2;
                else
                {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;
        return head;
    }

    ListNode *sortList(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        int len = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            len++;
            tail = tail->next;
        }
        return merge_sort(head, tail, len);
    }
};
