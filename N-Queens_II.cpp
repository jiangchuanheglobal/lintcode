class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        vector<int> usedCols;
        int nums = 0;
        DFS(nums, usedCols, 0, n);
        return nums;
    }
    
    void DFS(int& nums, vector<int>& usedCols, int row, int n) {
        if (row == n) {
            nums += 1;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (valid(usedCols, row, col)) {
                usedCols.push_back(col);
                DFS(nums, usedCols, row + 1, n);
                usedCols.pop_back();
            }
        }
    }
    
    bool valid(vector<int>& usedCols, int row, int col) {
        for (int i = 0; i < usedCols.size(); i++) {
            if (usedCols[i] == col) return false;
            if (row - i  == abs(usedCols[i] - col) ) return false;
        }
        return true;
    }
};


// DFS: 搜索以level行开始的所有valid N-Queens 方案个数

// DFS(nums, i);
