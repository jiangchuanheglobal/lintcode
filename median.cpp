class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        return quickSelect(nums, (nums.size() - 1) / 2);
    }
    
    int quickSelect(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start <= end) {
            int pivot_index = end;
            
            int i = start;
            int j = end;
            
            while (i <= j) {
                if (nums[j] < nums[pivot_index]) {
                    swap(nums, j, i);
                    i += 1;
                } else {
                    j -= 1;
                }
            }
            
            swap(nums, pivot_index, i);
            
            if (i == k) {
                break;
            } else if (k < i) {
                end = i - 1;
            } else {
                start = i + 1;
            }
        }
        
        return nums[k];
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
