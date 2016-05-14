class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    // fast, slow ptrs, fast in inner loop
    int minimumSize(vector<int> &nums, int s) {
        // write your code here
       int i, j;
       int size = INT_MAX;
       int sum = 0;
       for (i = 0, j = 0; i < nums.size(); i++) {
           while (j < nums.size() && sum < s) {
                sum += nums[j];
                j += 1;
           }
           if (sum >= s) {
                size = ::min(size, j - i);
           }
           sum -= nums[i];
       }
       return size == INT_MAX ? -1 : size;
    }
};
