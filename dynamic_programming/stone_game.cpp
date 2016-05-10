class Solution {
public:
    /**
     * @param A an integer array
     * @return an integer
     */
    int stoneGame(vector<int>& A) {
        // Write your code here
        
        int n = A.size();
        if (n < 2) return 0;
        
        vector<vector<int> > f(n, vector<int>(n, 0));
        vector<vector<bool> > vis(n, vector<bool>(n, false));
        vector<vector<int> > sum(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
           sum[i][i] = A[i];
           for (int j = i + 1; j < n; j++) {
               sum[i][j] = sum[i][j - 1] + A[j];
           }
        }
        // init sum
        return memory_search(0, n - 1, f, vis, sum);
    }
    
    int memory_search(int l, int r, vector<vector<int> >& f, vector<vector<bool> >& vis, vector<vector<int> >& sum) {
        if (vis[l][r]) {
            return f[l][r];
        }
        if (l == r) {
            vis[l][r] = true;
            f[l][r] = 0;
            return f[l][r];
        }
        
        f[l][r] = INT_MAX;
        
        for (int k = l; k < r; k++) {
            f[l][r] = ::min(f[l][r], memory_search(l, k, f, vis, sum) + memory_search(k + 1, r, f, vis, sum)
                                    + sum[l][r]);
        }
        vis[l][r] = true;
        return f[l][r];
    }
};
