/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return head;
        RandomListNode *cur = head, *next, *p, *head1, *cur1;
        while (cur)
        {
            next = cur->next;
            p = new RandomListNode(cur->label);
            cur->next = p;
            p->next = next;
            cur = next;
        }
        cur = head;
        while (cur)
        {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        head1 = cur1 = NULL;
        cur = head;
        while (cur)
        {
            next = cur->next->next;
            if (!head1)
            {
                head1 = cur1 = cur->next;
            }
            else
            {
                cur1->next = cur->next;
                cur1 = cur1->next;
            }
            cur->next = next;
            cur = cur->next;
        }
        return head1;
    }
};
