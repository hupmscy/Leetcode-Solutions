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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head || !head->next || !head->next->next)
            return NULL;
        ListNode *fast, *slow, *tmp1, *tmp2;
        fast = head->next->next;
        slow = head->next;
        while (fast != slow && fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!fast->next || !fast->next->next)
            return NULL;
        tmp1 = head;
        tmp2 = fast;
        while (tmp1 != tmp2)
        {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return tmp1;
    }
};
