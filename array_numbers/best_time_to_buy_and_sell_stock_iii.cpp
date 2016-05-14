class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int I = maxProfitI(prices);
        int II = maxProfitII(prices);
        return  I >= II ? I : II; 
    }
   
    int maxProfitII(vector<int> &prices) {
        int profit = maxTwoSubArrays(constructDiffArray(prices));
        return profit >= 0 ? profit : 0;
    }
    
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        
        // 1 3 -1
        // 1 4  3
        // 1 4  4
        // f[i] = max(A[i], f[i-1] + A[i]);
        if (nums.size() == 0) return 0;

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
    
    int maxProfitI(vector<int> &prices) {
        // write your code here
        int profit = maximumSubArraySum(constructDiffArray(prices));
        return profit >= 0 ? profit : 0;
    }
};
