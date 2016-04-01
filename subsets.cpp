class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	// write your code here
    	vector<vector<int> > results;
    	vector<int> list;
    	subsetsHelper(results, nums, list, 0);
    	return results;
    }
    
    void subsetsHelper(vector<vector<int> >& results, vector<int>& nums, vector<int>& list, int pos) {
        results.push_back(list);
        for (int i = pos; i < nums.size(); i++) {
            list.push_back(nums[i]);
            subsetsHelper(results, nums, list, i+1);
            list.pop_back();
        }
    }
};
