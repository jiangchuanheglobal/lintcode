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
        vector<bool> vis(num.size(), false);
        DFS(ans, path, vis, num, target, 0);
        return ans;
    }
    
    // trick thing is how to remove duplicate !!!
    void DFS(vector<vector<int> >& result, vector<int>& path, vector<bool>& vis, vector<int>& num, int target, int pos) {
        if (target == 0) {
           result.push_back(path);
           return;
        }
        
        for (int i = pos; i < num.size(); i++) {
            if (valid(i, vis, num, target)) {
                vis[i] = true;
                path.push_back(num[i]);
                DFS(result, path, vis, num, target - num[i], i + 1);
                vis[i] = false;
                path.pop_back();
            }
        }
    }
    
    bool valid(int i, vector<bool>& vis, vector<int>& num, int target) {
        if (i > 0 && num[i - 1] == num[i] && !vis[i - 1]) {
            return false;
        } else if (target - num[i] >= 0) {
            return true;
        } else {
            return false;
        }
    }
};
