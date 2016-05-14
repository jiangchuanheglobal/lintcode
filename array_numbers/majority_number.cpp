class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cnt = 0;
        int can = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                can = nums[i];
                cnt = 1;
            } else if (nums[i] == can) {
                cnt += 1;
            } else {
                cnt -= 1;
            }
           
        }
        return can;
    }
};
