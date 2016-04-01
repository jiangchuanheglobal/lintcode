class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        std::sort(A.begin(), A.end());
        vector<vector<int> > result;
        vector<int> path;
        
        DFS(result, path, A, k, target, 0);
        
        return result;
    }
    
    void DFS(vector<vector<int> >& result, vector<int>& path, vector<int>& A, int k, int target, int pos) {
        if (k < 0) return;
        
        if (k == 0 && target == 0) { // must have k elements in array !!!
            result.push_back(path);
            return;
        }
        
        for (int i = pos; i < A.size(); i++) {
            if (target - A[i] >= 0) {
                path.push_back(A[i]);
                DFS(result, path, A, k - 1, target - A[i], i + 1);
                path.pop_back();
            }
        }
    }
};
