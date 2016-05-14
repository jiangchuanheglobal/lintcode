class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int f = nums[0];
        int min_sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            f = ::min(nums[i], f + nums[i]);
            min_sum = ::min(min_sum, f);
        }
        return min_sum;
    }
};
