class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<vector<int> > results;
        vector<int> list;
        vector<int> nums(S);
        std::sort(nums.begin(), nums.end());
        subsetsHelper(results, nums, list, 0);
        return results;
    }
    void subsetsHelper(vector<vector<int> >& results, vector<int>& nums, vector<int>& list, int pos) {
        results.push_back(list);
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[i-1]) continue;
            
            list.push_back(nums[i]);
            subsetsHelper(results, nums, list, i+1);
            list.pop_back();
        }
    }
};
