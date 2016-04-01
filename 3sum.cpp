class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i && nums[i - 1] == nums[i]) continue;
            
           int j = i + 1;
           int k = nums.size() - 1;
           while (j < k) {
               if (j != i + 1 && nums[j - 1] == nums[j]) {
                   j += 1;
                   continue;
               }
               
               int sum = nums[i] + nums[j] + nums[k];
               if (sum == 0) {
                   vector<int> triple;
                   triple.push_back(nums[i]);
                   triple.push_back(nums[j]);
                   triple.push_back(nums[k]);
                   result.push_back(triple);
                   j += 1;
                   k -= 1;
               } else if (sum < 0) {
                   j += 1;
               } else {
                   k -= 1;
               }
           }
        }
        
        return result;
    }
};
