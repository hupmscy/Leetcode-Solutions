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

    #define SIZE 10000
    ListNode* heap[SIZE];
    int heapsize;

    void insert(ListNode *node)
    {
        heap[++heapsize] = node;
        move_up();
    }

    ListNode* extract()
    {
        ListNode *res = heap[1];
        heap[1] = heap[heapsize--];
        move_down();
        return res;
    }

    void move_up()
    {
        int cur = heapsize;
        int parent = heapsize/2;
        while (parent)
        {
            if (heap[cur]->val < heap[parent]->val)
                swap(heap[cur], heap[parent]);
            else
                break;
            cur = parent;
            parent/=2;
        }
    }

    void move_down()
    {
        int cur, min_ind;
        cur = 1;
        while (cur*2 <= heapsize)
        {
            min_ind = heap[cur]->val < heap[2*cur]->val ? cur : 2*cur;
            if (cur*2+1 <= heapsize)
                min_ind = heap[min_ind]->val < heap[2*cur+1]->val ? min_ind : 2*cur+1;
            if (min_ind != cur)
                swap(heap[cur], heap[min_ind]);
            else
                break;
            cur = min_ind;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0)
            return NULL;
        int k = lists.size();
        ListNode *head, *cur;
        heapsize = 0;
        for (int i = 0; i < k; i++)
            if (lists[i])
                insert(lists[i]);
        head = NULL;
        while (heapsize)
        {
            ListNode *node = extract();
            if (!head)
                head = cur = node;
            else
            {
                cur->next = node;
                cur = cur->next;
            }
            if (node->next)
            {
                heap[++heapsize] = node->next;
                move_up();
            }
        }
        return head;
    }
};
