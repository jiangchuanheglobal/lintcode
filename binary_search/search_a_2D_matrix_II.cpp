class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        
        int count = 0;
        int row = 0;
        int col = n - 1;
        while (row < m && col >= 0) {
            if (matrix[row][col] < target) {
                row += 1;
            } else if (matrix[row][col] > target) {
                col -= 1;
            } else {
                count += 1;
                row += 1;
                col -= 1;
            }
        }
        
        return count;
    }
};
