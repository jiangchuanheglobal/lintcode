class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> > ans;
        vector<int> path;
        DFS(ans, path, n, k, 1);
        return ans;
    }
    
    void DFS(vector<vector<int> >& result, vector<int>& path, int n, int k, int pos) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        
        for (int i = pos; i <= n; i++) {
            path.push_back(i);
            DFS(result, path, n, k, i + 1);
            path.pop_back();
        }
    }
};
