class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        std::sort(candidates.begin(), candidates.end());
        
        vector<vector<int> > result;
        vector<int> path;
        
        DFS(result, path, 0, target, candidates);
        return result;
    }
    
    void DFS(vector<vector<int> >& result, vector<int>& path, int pos, int target, vector<int>& candidates) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] > target) return;
            path.push_back(candidates[i]);
            DFS(result, path, i, target - candidates[i], candidates);
            path.pop_back();
        }
    }
};


// define:
// DFS: 搜索以can[i]开头的所有sum等于target的组合，放在result中
// remainings 
//       []
// [2]       [3]         [6]     [7]

// [2,2] [2,3]  [3,3]
 
// [2,2,2]  x    x

