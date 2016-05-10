class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        int n = A.size();
        if (n == 0) return 0;
        
        int m = A[0].size();
        vector<vector<int> > f(n, vector<int>(m, 0));
        vector<vector<bool> > vis(n, vector<bool>(m , false));
        
        int longest = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                longest = ::max(longest, memory_search(A, f, vis, i, j));
            }
        }
        return longest;
    }
    
    int memory_search(vector<vector<int>>& A, vector<vector<int> >& f, vector<vector<bool> >& vis, int x, int y) {
        if (vis[x][y]) {
            return f[x][y];
        }
        
        vis[x][y] = true; // in visit , not visit, after visit
        f[x][y] = 1;
        int n = A.size();
        int m = A[0].size();
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        
        for (int i = 0; i < 4; i++) {
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && A[n_x][n_y] < A[x][y]) {
                f[x][y] = ::max(f[x][y], memory_search(A, f, vis, n_x, n_y) + 1);
            }
        }
        return f[x][y];
    }
};
