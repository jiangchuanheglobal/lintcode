class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string> > ans;
        vector<int> path;
        DFS(n, 0, ans, path);
        return ans;
    }
    
    void DFS(int n, int row, vector<vector<string> >& result,
    vector<int>& path) {
        if (row == n) {
            result.push_back(convert2Board(path));
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (valid(path, row, col)) {
                path.push_back(col);
                DFS(n, row + 1, result, path);
                path.pop_back();
            }
        }
    }
    
    bool valid(vector<int>& path, int x1, int y1) {
        for (int x = path.size() - 1; x >= 0; x--) {
            int y = path[x];
            
            if (y == y1) return false;
            if (x1 - x == y - y1) return false;
            if (x - x1 == y - y1) return false;
        }
        return true;
    }
    
    vector<string> convert2Board(vector<int>& path) {
        vector<string> board;
        int n = path.size();
        for (int row = 0; row < n; row++) {
            string line = "";
            for (int col = 0; col < n; col++) {
                if (col == path[row]) {
                    line.push_back('Q');
                } else {
                    line.push_back('.');
                }
            }
            board.push_back(line);   
        }
        return board;
    }
    
};
