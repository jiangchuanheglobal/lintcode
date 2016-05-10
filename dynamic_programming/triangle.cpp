class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        
        // bottom up
        
        // define state
        // f(x, y)
        vector<vector<int> > f = triangle;
        
        // init
        
        // function
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[i][j] = ::min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
            }
        }
        
        return f[0][0];
    }
};
