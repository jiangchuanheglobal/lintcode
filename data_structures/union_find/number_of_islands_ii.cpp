/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
class UnionFind {
  public:
  UnionFind() {
  }
  
  int Find(int x) {
      int parent = x;
      while (father[parent]!= parent) {
          parent = father[parent];
      }
      // path compressed
      int y = x;
      while (father[y] != y) {
          int tmp = father[y];
          father[y] = parent;
          y = tmp;
      }
      return parent;
  }
  
  void Union(int x, int y) {
      int f_x = Find(x);
      int f_y = Find(y);
      if (f_x != f_y) {
          father[f_x] = f_y;
      }
  }
  std::unordered_map<int, int> father;  
};

class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        // Write your code here
        vector<int> result;
        UnionFind uf;
        int cnt = 0;
        const int offset_x[] = {-1, 0, 1, 0};
        const int offset_y[] = {0, 1, 0, -1};
        
        for (auto& p : operators) {
            cnt += 1;
            uf.father[p.x*m + p.y] = p.x*m + p.y;
            for (int i = 0; i < 4; i++) {
                if (p.x+offset_x[i] < 0 || p.x+offset_x[i] >= n
                || p.y+offset_y[i] < 0 || p.y+offset_y[i] >= m) continue;
                
                int x = (p.x+offset_x[i])*m + p.y+offset_y[i];
                // Exist
                if (uf.father.find(x) != uf.father.end()) {
                    if (uf.Find(x) != uf.Find(p.x*m+p.y)) {
                        uf.Union(p.x*m + p.y, x);
                        cnt -= 1;
                    }
                }
            }
            result.push_back(cnt);
            
        }
        
        return result;
    }
};
