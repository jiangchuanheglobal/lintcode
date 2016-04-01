class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int n = nums.size();
        vector<vector<int> > f(n + 1, vector<int>(k + 1, 0));
        
        for (int i=0; i <= n; i++) f[i][0] = 0;  
        
        for (int j = 1; j <= k; j++) { // j comes first
            for (int i = j; i <= n; i++) {
                f[i][j] = INT_MIN; // why ?
                
                int local = 0;
                int global = INT_MIN;
                for (int t = i - 1; t >= j - 1; t--) {
                    local = ::max(nums[t], local + nums[t]);
                    global = ::max(global, local);
                    f[i][j] = ::max(f[i][j], f[t][j - 1] + global);
                }
            }
        }
        return f[n][k];
    }
};

