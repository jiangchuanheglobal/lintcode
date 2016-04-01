class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<bool> used(nums.size(), false);
        vector<vector<int> > results;
        vector<int> list;
        
        permuteHelper(results, list, nums, used);
        
        return results;
    }
    
    void permuteHelper(vector<vector<int >>& results, vector<int>& list, vector<int>& nums, vector<bool> used)
    {
        if (list.size() == nums.size() && nums.size() > 0)
            results.push_back(list);
            
        for (int i = 0; i < nums.size(); i++) {
            if (canTake(vis, i)) {
              used[i] = true;
              list.push_back(nums[i]);
              permuteHelper(results, list, nums, used);
              list.pop_back();
              used[i] = false;
            }
        }
    }

    bool canTake(vector<bool>& vis, int i) {
      return !vis[i];
    }
};
