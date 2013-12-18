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

    int get_len(ListNode *l)
    {
        int res = 0;
        while (l)
        {
            res++;
            l = l->next;
        }
        return res;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;
        ListNode *pre, *res;
        int v, c;
        int len1 = get_len(l1);
        int len2 = get_len(l2);
        if (len1 < len2)
            swap(l1, l2);
        res = l1;
        v = c = 0;
        while (l1 && l2)
        {
            v = l1->val+l2->val+c;
            l1->val = v%10;
            c = v/10;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1)
        {
            v = l1->val+c;
            l1->val = v%10;
            c = v/10;
            if (c == 0)
                break;
            pre = l1;
            l1 = l1->next;
        }
        if (c)
            pre->next = new ListNode(c);
        return res;
    }
};
