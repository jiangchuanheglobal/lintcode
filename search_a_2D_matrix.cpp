class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        int start, end, mid, m, n;
        if (matrix.size() == 0) return false;
        m = matrix.size();
        n = matrix[0].size();
        start = 0;
        end = m*n - 1;
        int x, y;
        while (start + 1 < end) {
            int mid = start + (end-start)/2;
            OneToTwoCoord(mid, n, x, y);
            if (matrix[x][y] <= target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        OneToTwoCoord(start, n, x, y);
        if (matrix[x][y] == target) return true;
        OneToTwoCoord(end, n, x, y);
        if (matrix[x][y] == target) return true;
        return false;
    }
    
    void OneToTwoCoord(int i, int n, int&x, int&y) {
        // Pass i, returns its two dimensonal coord(x, y)
        // @param n, colums
        x = i / n;
        y = i % n;
    }
};
