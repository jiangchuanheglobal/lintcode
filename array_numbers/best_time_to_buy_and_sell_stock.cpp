class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
     
    int maximumSubArraySum(vector<int> nums) {
        if (nums.size() == 0) return 0;
        
        int max_sum = nums[0];
        int f = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            f = ::max(nums[i], f + nums[i]);
            max_sum = ::max(max_sum, f);
        }
        
        return max_sum;
    }
    
    vector<int> constructDiffArray(vector<int>& nums) {
        vector<int> result;
        for (int i = 1; i < nums.size(); i++) {
            result.push_back(nums[i] - nums[i-1]);
        }
        return result;
    }
    
    int maxProfit(vector<int> &prices) {
        // write your code here
        int profit = maximumSubArraySum(constructDiffArray(prices));
        return profit >= 0 ? profit : 0;
    }
};
