class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<int> ans = nums;
        if (n < 2) return ans;
        
        int p = n - 2;
        while (p >= 0 && ans[p] <= ans[p + 1]) {
            p -= 1;
        }
        
        if (p < 0) {
            reverse(0, ans);
            return ans;
        } else {
            reverse(p + 1, ans);
            int q = p + 1;
            while (q < n && ans[p] <= ans[q]) {
                q += 1;
            }
            swap(ans[p], ans[q]);
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
