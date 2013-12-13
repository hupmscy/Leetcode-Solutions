/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return node;
        UndirectedGraphNode* node_copy = new UndirectedGraphNode(node->label);
        UndirectedGraphNode *cur, *cur_copy;
        map<int, UndirectedGraphNode*> node_list;
        map<int, UndirectedGraphNode*> node_list_copy;
        queue<UndirectedGraphNode*> q1;
        queue<UndirectedGraphNode*> q2;
        node_list[node->label] = node;
        node_list_copy[node->label] = node_copy;
        q1.push(node);
        q2.push(node_copy);
        while (!q1.empty())
        {
            cur = q1.front();
            q1.pop();
            cur_copy = q2.front();
            q2.pop();
            for (int i = 0; i < cur->neighbors.size(); i++)
            {
                int v = cur->neighbors[i]->label;
                if (node_list.find(v) == node_list.end())
                {
                    UndirectedGraphNode *p = new UndirectedGraphNode(v);
                    node_list_copy[v] = p;
                    node_list[v] = cur->neighbors[i];
                    q1.push(node_list[v]);
                    q2.push(node_list_copy[v]);
                }
                cur_copy->neighbors.push_back(node_list_copy[v]);
            }
        }
        return node_copy;
    }
};
