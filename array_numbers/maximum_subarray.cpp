class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        
        // DP
        
        // state
        int f[nums.size()];
        
        // init
        f[0] = nums[0];
        int maxSum = nums[0];
        
        // recursion
        for (int i = 1; i < nums.size(); i++) {
            f[i] = ::max(f[i - 1] + nums[i], nums[i]);
            maxSum = ::max(maxSum, f[i]);
        }
        return maxSum;
    }
};
