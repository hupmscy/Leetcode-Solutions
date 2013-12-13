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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head || !head->next || !head->next->next)
            return false;
        ListNode *fast, *slow;
        fast = slow = head;
        slow = slow->next;
        fast = fast->next->next;
        while (fast != slow && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!fast->next || !fast->next->next)
            return false;
        else
            return true;
    }
};
