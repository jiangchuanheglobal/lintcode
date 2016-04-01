class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            if (nums[end] < k) {
                swap(nums, start, end);
                start += 1;
            } else {
                end -= 1;
            }
        }
        
        return start;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
