class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int n = A.size();
        vector<int> f(n, 0);
        f[0] = 0;
        
        for (int i = 1; i < n; i++) {
            f[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (f[j] < INT_MAX && j + A[j] >= i) {
                    f[i] = f[j] + 1;
                    break;
                }
            }
        }
        
        return f[n - 1];
    }
};
