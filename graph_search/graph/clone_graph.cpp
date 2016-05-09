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
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (!node) return node;
        // BFS, collect all nodes
        set<UndirectedGraphNode*> nodes;
        queue<UndirectedGraphNode*> que;
        
        nodes.insert(node);
        que.push(node);
        while (!que.empty()) {
            UndirectedGraphNode* curt = que.front();
            que.pop();
            
            for (auto it = curt->neighbors.begin(); it != curt->neighbors.end(); it++) {
                UndirectedGraphNode* nb = *it;
                if (nodes.find(nb) == nodes.end()) {
                    nodes.insert(nb);
                    que.push(nb);
                }
            }
        }
        
        // copy to new nodes
        map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;
        for (auto& n : nodes) {
            mapping[n] = new UndirectedGraphNode(n->label);
        }
        
        // make edges
        for (auto n: nodes) {
            for (auto it = n->neighbors.begin(); it != n->neighbors.end(); it++) {
                UndirectedGraphNode* nb = *it;
                mapping[n]->neighbors.push_back(mapping[nb]);
            }
        }
        
        return mapping[node];
    }
};
