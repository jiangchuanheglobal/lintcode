/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> result;
        
        map<DirectedGraphNode*, int> directions;

        for (int i = 0; i < graph.size(); i++) {
            directions[graph[i]] = 0;
        }
        
        for (int i = 0; i < graph.size(); i++) {
            for (auto it = graph[i]->neighbors.begin(); it != graph[i]->neighbors.end(); it++) {
                directions[*it] += 1;
            }
        }
        
        queue<DirectedGraphNode*> q;
        for (auto it = directions.begin(); it != directions.end(); it++) {
            if (it->second == 0) {
                q.push(it->first);
            }
        }
        
        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            result.push_back(node);
            for (auto it = node->neighbors.begin(); it != node->neighbors.end(); it++) {
                DirectedGraphNode* nb = *it;
                directions[nb] -= 1;
                if (directions[nb] == 0) {
                    q.push(nb);
                }
            }
        }
        
        return result;   
    }
};

// 先收集每个节点的入度



// 把入度为0的节点放入队列
// 每次取一个节点，给其指向的邻接点入度减一，若减一后入度变为0，则放入队列
