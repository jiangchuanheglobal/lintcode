class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        // write your code here
        
        // define state
        // f(first i items, size) = can or cannot fill
        // ans = max{size, f(items, size) == true}
        
        
        int n = A.size();
        if (n == 0) return 0;
        
        vector<vector<bool> > f(n + 1, vector<bool>(m + 1, false));
        
        f[0][0] = true;
        
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (f[i - 1][j] || (j - A[i - 1] >= 0 && f[i - 1][j - A[i - 1]])) {
                    f[i][j] = true;
                } else {
                    f[i][j] = false;
                }
                
                if (f[i][j]) {
                    ans = ::max(ans, j);
                }
            }
        }
        
        return ans;
    }
};
