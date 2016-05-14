class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */    
    void sortColors(vector<int> &nums) {
        // write your code here
        int start = 0;
        int end = nums.size() - 1;
        
        int i = end;
        
        while (start <= i) {
            if (nums[i] == 0) {
                swap(nums, start, i);
                start += 1;
            } else if (nums[i] == 2) {
                swap(nums, i, end);
                end -= 1;
                i -= 1;
            } else {
                i -= 1;
            }
        }
        
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
