class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        std::sort(nums.begin(), nums.end());
        // int n = nums.size();
        // if (n == 0) return;
        // if (n == 1) return;

        // while (nums[0] > nums[n - 1]) {
        //     int head = nums[0];
        //     rotateLeft(nums);
        //     nums[n - 1] = head;
        // }
    }
    
    void rotateLeft(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        while (i < n) {
            nums[i - 1] = nums[i];
            i += 1;
        }
    }
