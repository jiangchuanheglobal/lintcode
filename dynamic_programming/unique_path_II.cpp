class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */ 
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // write your code here
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        if (obstacleGrid[0][0] == 1) return 0;
        
        int n = obstacleGrid[0].size();
        vector<vector<int> > f(m, vector<int>(n, 0));
        
        f[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                f[i][0] = f[i - 1][0];
            } else {
                f[i][0] = 0;
            }
        }
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0) {
                f[0][i] = f[0][i - 1];
            } else {
                f[0][i] = 0;
            }
        }
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                } else {
                    f[i][j] = 0;
                }
            }
        }
        return f[m - 1][n - 1];
    }
};
