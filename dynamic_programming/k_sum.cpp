class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        // wirte your code here
        int n = A.size();
        int f[n + 1][k + 1][target + 1];
        
        // init
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = 0; s <= target; s++) {
                    f[i][j][s] = 0;
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            f[i][0][0] = 1;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k && j <= i; j++) {
                for (int s = 1; s <= target; s++) {
                    f[i][j][s] = 0;
                    if (s - A[i - 1] >= 0) {
                        f[i][j][s] += f[i - 1][j - 1][s - A[i - 1]];
                    }
                    f[i][j][s] += f[i - 1][j][s];
                }
            }
        }
        
        
        return f[n][k][target];
    }
};

