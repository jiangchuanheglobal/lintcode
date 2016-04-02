class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        std::sort(num.begin(), num.end());
        vector<vector<int> > ans;
        vector<int> path;
        DFS(ans, path, num, target, 0);
        return ans;
    }
    
    // trick thing is how to remove duplicate !!!
    void DFS(vector<vector<int> >& result, vector<int>& path, vector<int>& num, int target, int pos) {
        if (target == 0) {
           result.push_back(path);
           return;
        }
       
        int prevUsed = -1;
        for (int i = pos; i < num.size(); i++) {
            if (valid(num, i, prevUsed)) {
                path.push_back(num[i]);
                DFS(result, path, num, target - num[i], i + 1);
                path.pop_back();
                prevUsed = i;
            }
        }
    }

    bool valid(vector<int>& num, int curt, int prev) {
      if (prev < 0) {
        return true;
      } else if (num[prev] == num[i]) {
        return false;
      } else {
        return true;
      }
    }
};
