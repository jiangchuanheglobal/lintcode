class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        // write your code here
        int n = A.size();
        vector<vector<int> > f(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j - A[i - 1] >= 0) {
                    f[i][j] = ::max(f[i - 1][j], f[i - 1][j - A[i - 1]] + V[i - 1]);
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        
        return f[n][m];
    }
};
