class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
        // Write your code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int> > ans;
        vector<vector<int> > presum(rows + 1, vector<int>(cols, 0));
        
        // init presum matrix
        for (int j = 0; j < cols; j++) {
            for (int i = 1; i < rows + 1; i++) {
                presum[i][j] = presum[i - 1][j] + matrix[i - 1][j];
            }
        }
    
        for (int top = 0; top < rows + 1; top++) {
            for (int down = top + 1; down < rows + 1; down++) {
                
                vector<int> linepresum = computeLinePresum(presum, top, down);
                map<int, int> exist;
                int i = 0;
                while (i < linepresum.size() && exist.find(linepresum[i]) == exist.end()) {
                    exist[linepresum[i]] = i;
                    i += 1;
                }
                if (i < linepresum.size()) {
                    // find it!
                    vector<int> p{top, exist[linepresum[i]]};
                    vector<int> p2{down - 1, i - 1};
                    ans.push_back(p);
                    ans.push_back(p2);
                    return ans;
                }
            }
        }
        return ans;
    }
    
    vector<int> computeLinePresum(vector<vector<int> >& presum, int top, int down) {
        vector<int> ans(presum[0].size() + 1, 0);
        
        for (int i = 1; i < presum[0].size() + 1; i++) {
            int n = presum[down][i - 1] - presum[top][i - 1];
            ans[i] = n + ans[i - 1];
        }
        
        return ans;
    }
};
