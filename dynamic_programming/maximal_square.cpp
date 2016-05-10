class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        vector<vector<int> > f(m, vector<int>(n, 0));
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 1) {
                f[i][0] = 1;
                ans = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 1) {
                f[0][i] = 1;
                ans = 1;
            }
        }
        
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    f[i][j] = ::min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
                } else {
                    f[i][j] = 0;
                }
                ans = ::max(ans, f[i][j]);
            }
        }
        return ans * ans;
    }
    
    // int brute_force(vector<vector<int> > &matrix) {
    //     int m = matrix.size();
    //     if (m == 0) return 0;
    //     int n = matrix[0].size();
        
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //           for (int len = 1; i + len < m && j + len < n; len++) {
                   
    //           }
    //         }
    //     }
    // }
};
