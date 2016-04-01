class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        if (nums.size() < 3) return INT_MAX;
        // write your code here
        std::sort(nums.begin(), nums.end());
        
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    j += 1;
                } else {
                    k -= 1;
                }
                closest = abs(sum - target) < abs(closest - target) ? sum : closest;
            }
           
        }
        
        return closest;
    }
};
