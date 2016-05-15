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
      int y = father[x];
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
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    bool IsEdgeEntry(int x, int y, int m, int n) {
        return x == 0 || x == m-1 || y == 0 || y == n-1;
    }
    void unionHelper(UnionFind& uf, int x, int y, vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        static int offsetx[] = {0, -1, 0, 1};
        static int offsety[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int n_x = x + offsetx[i];
            int n_y = y + offsety[i];
            
            if (n_x < 0 || n_x == m || n_y < 0 || n_y == n) continue;
                
            if (board[n_x][n_y] == 'O') {
                int father_n = uf.Find(n_x * n + n_y);
                int father_me = uf.Find(x * n + y);
                if (IsEdgeEntry(father_n/n, father_n%n, m, n)) {
                    uf.Union(father_me,father_n);
                } else if (IsEdgeEntry(father_me/n, father_me%n, m, n)) {
                    uf.Union(father_n, father_me);
                } else {
                    uf.Union(n_x*n+n_y, x*n+y);
                }
            }
        }
    }
    
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        UnionFind uf;
        // Init
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') uf.father[i*n + j] = i*n+j;
            }
        }
        
        // union
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    unionHelper(uf, i, j, board);
            }
        }
        // set inner land to 'x'
        for (auto it = uf.father.begin(); it != uf.father.end(); it++) {
            int key = it->first;
            int father = uf.Find(key);
            if (!IsEdgeEntry(father/n, father%n, m, n)) {
                board[key/n][key%n] = 'X';
            }
        }
    }
};
