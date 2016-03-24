class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int size = nums.size();
        if (size < 2) {             // why size == 1 returns [1] ?
            vector<long long> ans;
            if (size == 1) {         
                ans.push_back(1);
            }
            return ans;
        }
        vector<long long> left(size, 0);
        vector<long long> right(size, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left[i] = nums[i];
            } else {
                left[i] = left[i - 1] * nums[i];
            }
        }
        for (int i = size - 1; i >= 0; i--) {
            if (i == size - 1) {
                right[i] = nums[i];
            } else {
                right[i] = right[i + 1] * nums[i];
            }
        }
        
        vector<long long> ans (size, 0);
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                ans[i] = right[i + 1];
            } else if (i == size - 1) {
                ans[i] = left[i - 1];
            } else {
                ans[i] = left[i - 1] * right[i + 1];
            }
        }
        return ans;
    }
};
