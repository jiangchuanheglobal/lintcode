class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> left_largest(n, 0);
        vector<int> right_smallest(n, 0);
        
        vector<int> left_smallest(n, 0);
        vector<int> right_largest(n, 0);
        
        int local_smallest = nums[0];
        int local_largest = nums[0];
        left_largest[0] = nums[0];
        left_smallest[0] = nums[0];
        for (int i = 1; i < n; i++) {
            local_smallest = ::min(local_smallest + nums[i], nums[i]);
            local_largest = ::max(local_largest + nums[i], nums[i]);
            
            left_largest[i] = ::max(left_largest[i - 1], local_largest);
            left_smallest[i] = ::min(left_smallest[i - 1], local_smallest);
        }
        
        local_smallest = nums[n - 1];
        local_largest = nums[n - 1];
        right_smallest[n - 1] = nums[n - 1];
        right_largest[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            local_smallest = ::min(local_smallest + nums[i], nums[i]);
            local_largest = ::max(local_largest + nums[i], nums[i]);
            
            right_largest[i] = ::max(right_largest[i + 1], local_largest);
            right_smallest[i] = ::min(right_smallest[i + 1], local_smallest);
        }
        
        int ans = INT_MIN;
        int n1, n2;
        for (int i = 0; i < n - 1; i++) {
            n1 = abs(left_largest[i] - right_smallest[i + 1]);
            n2 = abs(left_smallest[i] - right_largest[i + 1]);
            ans = ::max(ans, ::max(n1, n2));
        }
        
        return ans;
    }
};
