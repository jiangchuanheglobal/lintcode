class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int len = nums.size();
        if (len < 2) return len;
        
        int slow = 0;
        int fast = 1;
        while (fast < len) {
            if (nums[slow] != nums[fast]) {
                slow += 1;
                nums[slow] = nums[fast];
                fast += 1;
            } else {
                fast += 1;
            }
            
        }
        return slow + 1;
    }
};
