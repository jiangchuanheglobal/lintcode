class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<int> ans = nums;
        if (n < 2) return ans;
        
        // find index p
        int p = n - 2;
        while (p >= 0 && ans[p] >= ans[p + 1]) {
            p -= 1;
        }
        
        if (p < 0) {
            reverse(0, ans);
            return ans;
        } else {
            // find index q
            int q = n - 1;
            while (q >= 0 && ans[q] <= ans[p]) {
                q -= 1;
            }
            
            swap(ans[p], ans[q]);
            reverse(p + 1, ans);
            return ans;
        }
    }
    
    void reverse(int start, vector<int>& nums) {
        int end = nums.size() - 1;
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }
    }
    
    void swap(int& i, int& j) {
        int tmp = i;
        i = j;
        j = tmp;
    }
};
