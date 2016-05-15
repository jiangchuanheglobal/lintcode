
class UnionFind {
  public:
  UnionFind(int n) {
      for (int i = 0; i < n; i++)
        father.push_back(i);
  }
  
  void Union(int x, int y) {
      int f_x = Find(x);
      int f_y = Find(y);
      if (f_x != f_y)
        father[f_x] = f_y;
  }
  
  int Find(int x) {
      int parent = x;
      while (father[parent] != parent) {
         parent = father[parent];
      }
      return parent;
  }
  vector<int> father;  
};


class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if (edges.size() + 1 != n) return false;
        
        UnionFind ufind(n);
        for (int i = 0; i < edges.size(); i++) {
            // edges[i][0], edges[i][1]
            if (ufind.Find(edges[i][0]) == ufind.Find(edges[i][1])) {
                return false;
            }
            ufind.Union(edges[i][0], edges[i][1]);
        }
        return true;
    }
