class LRUCache{
public:

    struct Node
    {
        int key, val;
        bool used;
        Node *next;
        Node() {key = val = 0; next = NULL; used = false;}
    };

    Node *res, *head;
    int cap, size;

    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        res = new Node[capacity];
        for (int i = 0; i < cap-1; i++)
            res[i].next = &res[i+1];
        head = NULL;
    }

    int get(int key) {

        Node *cur = head;
        Node *pre;
        while (cur && cur->key != key)
        {
            pre = cur;
            cur = cur->next;
        }
        if (!cur)
            return -1;
        if (head != cur)
        {
            pre->next = cur->next;
            cur->next = head;
            head = cur;
        }
        return cur->val;
    }

    void set(int key, int value) {
        if (get(key) != -1)
            head->val = value;
        else
        {
            if (cap == size)
            {
                Node *pre = NULL, *cur = head;
                while (cur->next)
                {
                    pre = cur;
                    cur = cur->next;
                }
                cur->key = key;
                cur->val = value;
                if (pre)
                {
                    pre->next = NULL;
                    cur->next = head;
                    head = cur;
                }
            }
            else
            {
                size++;
                int i;
                for (i =0; i < cap; i++)
                    if (!res[i].used)
                        break;
                res[i].used = true;
                res[i].next = head;
                head = &res[i];
                head->key = key;
                head->val = value;
            }
        }
    }
};
