class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int len = nums.size();
        if (len == 0) return 0;
        vector<int> f(len, 1);
        int max_len_subseq = 1;
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] <= nums[i]) {
                    f[i] = ::max(f[i], f[j] + 1);
                }
            }
            max_len_subseq = ::max(max_len_subseq, f[i]);
        }
        
        return max_len_subseq;
    }
};
