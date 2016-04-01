class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        
        // 1 3 -1
        // 1 4  3
        // 1 4  4
        // f[i] = max(A[i], f[i-1] + A[i]);
        int n = nums.size();
        int leftMax[nums.size()];
        int rightMax[nums.size()];
        leftMax[0] = nums[0];
        rightMax[n - 1] = nums[n - 1];
        
        int localLeft = nums[0];
        for (int i = 1; i < n; i++) {
            localLeft = ::max(nums[i], localLeft + nums[i]);
            leftMax[i] = ::max(leftMax[i - 1], localLeft);
        }
        int rightLocal = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightLocal = ::max(nums[i], rightLocal + nums[i]);
            rightMax[i] = ::max(rightMax[i + 1], rightLocal);
        }
        
        // bar
        int maxTwo = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            maxTwo = ::max(maxTwo, leftMax[i] + rightMax[i + 1]);
        }
        return maxTwo;
    }
};
