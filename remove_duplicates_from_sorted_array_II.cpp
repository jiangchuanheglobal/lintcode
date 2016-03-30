class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if (len < 3) return len;
        
        int slow = 0;
        int fast = 1;
        int occur = 0;
        while (fast < len) {
            if (nums[slow] != nums[fast]) {
                occur = 0;
                slow += 1;
                nums[slow] = nums[fast];
                fast += 1;
            } else {
                occur += 1;
                if (occur < 2) {
                    slow += 1;
                    nums[slow] = nums[fast];
                    fast += 1;
                } else {
                    fast += 1;
                }
            }
        }
        return slow + 1;
    }
};
