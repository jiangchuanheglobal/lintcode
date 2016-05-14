class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        if (nums.size() == 0) return 0;
        int minCur = nums[0];
        int maxCur = nums[0];
        int maxGlobal = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int tmp = minCur;
            minCur = ::min(nums[i], ::min(nums[i]*minCur, nums[i]*maxCur));
            maxCur = ::max(nums[i], ::max(nums[i]*tmp, nums[i]*maxCur));
            maxGlobal = ::max(maxGlobal, ::max(minCur, maxCur));
        }
        
        return maxGlobal;
        
    }
