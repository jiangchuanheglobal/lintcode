class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> ans(1, 0);
        
        for (int i = 0; i < n; i++) {
            vector<int> half = ans;
            std::reverse(half.begin(), half.end());
            addOne(half, i);
            ans.insert(ans.end(), half.begin(), half.end());
        }
        
        return ans;
    }
    
    void addOne(vector<int>& nums, int pos) {
        for (auto& n : nums) {
            n |= 1 << pos;
        }
    }
};
