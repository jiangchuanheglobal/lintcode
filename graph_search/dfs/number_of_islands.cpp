
// class UFind {
//   public:
//   int Find(int x) {
//       int parent = x;
//       while (father.at(parent) != parent) {
//           parent = father.at(parent);
//       }
//       return parent;
//   }
  
//   void union(int x, int y) {
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
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if (grid.size() == 0) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    count += 1;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
    
    void DFS(vector<vector<bool>>& grid, int x, int y) {
        if (x < 0 || x >= grid.size()
        || y < 0 || y >= grid[0].size()) return;
        if (grid[x][y]) {
            grid[x][y] = false;
            DFS(grid, x-1, y);
            DFS(grid, x+1, y);
            DFS(grid, x, y-1);
            DFS(grid, x, y+1);
        }
    }
};
