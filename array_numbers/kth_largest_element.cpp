class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int swap(vector<int>& nums, int i, int j) {
        int tmp;
        tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
    }
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int left = 0;
        int right = nums.size() - 1;
        int pivot;
        while (left <= right) {
            int i, j;
            
            pivot = left;
            for (i = left+1, j = left+1; j <= right; j++) {
                if (nums[j] < nums[pivot]) {
                    swap(nums, i, j);
                    i += 1;
                }
            }
            
            swap(nums, pivot, i-1);
            pivot = i-1;
            
            if (pivot == nums.size() - k) {
                break;
            } else if (pivot < nums.size() - k) {
                left = pivot + 1;
            } else {
                right = pivot - 1;
            }
        }
        return nums[pivot];
    }
};
