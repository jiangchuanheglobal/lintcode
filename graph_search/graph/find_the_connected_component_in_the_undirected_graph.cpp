/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// class UFind {
//   public:
//   int Find(int x) {
//       int parent = x;
//       while (father.at(parent) != parent) {
//           parent = father.at(parent);
//       }
//       return parent;
//   }
  
//   void Union(int x, int y) {
//       int f_x = Find(x);
//       int f_y = Find(y);
//       if (f_x != f_y) {
//           father[f_y] = f_x;
//       }
//   }
//   unordered_map<int, int> father;
// };

class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int>> result;
        set<UndirectedGraphNode*> visit;
        
        
        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            if (visit.find(*it) == visit.end()) {
                BFS(result, *it, visit);
            }
        }
        return result;
    }
    
    void BFS(vector<vector<int>>& result, 
    UndirectedGraphNode* node, set<UndirectedGraphNode*>& visit) {
        vector<int> row;
        queue<UndirectedGraphNode*> nodeQue;
        
        nodeQue.emplace(node);
        visit.insert(node);
        while (!nodeQue.empty()) {
            UndirectedGraphNode* curt = nodeQue.front();
            nodeQue.pop();
            row.push_back(curt->label);
            for (auto it = curt->neighbors.begin(); it != curt->neighbors.end(); it++) {
                if (visit.find(*it) == visit.end()) {
                    nodeQue.emplace(*it);
                    visit.insert(*it);
                }
            }
        }
        sort(row.begin(), row.end());
        result.push_back(row);
    }
};
