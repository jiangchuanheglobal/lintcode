/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
 class UnionFind {
  public:
  UnionFind() {
  }
  UnionFind(int n) {
      for (int i = 0; i < n; i++)
        father[i+1] = i+1;
  }
  
  void Union(int x, int y) {
      int f_x = Find(x);
      int f_y = Find(y);
      if (f_x != f_y)
        father[f_x] = f_y;
  }
  
  // has path compression feature
  int Find(int x) {
      int parent = x;
      while (father[parent] != parent) {
         parent = father[parent];
      }
      while (x != parent) {
          int next = father[x];
          father[x] = parent;
          x = next;
      }
      return parent;
  }
  map<int, int> father;  
};

class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
     
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        // create and init union find
        UnionFind uf;
        for (auto& i : nodes) {
            uf.father[i->label] = i->label;
        }
        
        // do union
        for (auto& node : nodes) {
            for (auto& nb : node->neighbors) {
                if (uf.Find(node->label) != uf.Find(nb->label)) {
                    uf.Union(node->label, nb->label);
                }
            }
        }
        vector<vector<int>> result;
        
        // collect member for each weak connected component
        map<int, vector<int>> group;
        for (auto& node : nodes) {
           int f = uf.Find(node->label);
           if (group.find(f) == group.end()) {
               group[f] = vector<int>();
           }
           group[f].push_back(node->label);
        }
        // dump each component into result array
        for (auto it = group.begin(); it != group.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
};
