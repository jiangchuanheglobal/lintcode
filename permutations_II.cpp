class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        vector<vector<int> > results;
        vector<int> list;
        vector<bool> used(nums.size(), false);
        
        std::sort(nums.begin(), nums.end());
        permuteHelper(results, list, nums, used);
        
        return results;
    }
    
    void permuteHelper(vector<vector<int> >& results, vector<int>& list, vector<int>& nums, vector<bool> used)
    {
        if (nums.size() > 0 && list.size() == nums.size()) {
            results.push_back(list);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (canTake(used, i)) {
              used[i] = true;
              list.push_back(nums[i]);
              permuteHelper(results, list, nums, used);
              used[i] = false;
              list.pop_back();
            }
        }
    }
    bool canTake(vector<bool>& vis, int i) {
      if (vis[i]) {
        return false;
      } else if (i > 0 && nums[i] == nums[i-1] && !vis[i]) {
        return false;
      } else {
        return true;
      }
    }
};
