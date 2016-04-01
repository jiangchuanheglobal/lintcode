class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int lenA = A.length();
        int lenB = B.length();
        
        // define
        vector<vector<int> > f(lenA + 1, vector<int>(lenB + 1, 0));
        
        // init
        for (int i = 0; i <= lenA; i++) {
            f[i][0] = 0;
        }
        for (int j = 0; j <= lenB; j++) {
            f[0][j] = 0;
        }
        
        // function
        for (int i = 1; i <= lenA; i++) {
            for (int j = 1; j <= lenB; j++) {
                if (A[i - 1] == B[j - 1]) {
                    f[i][j] = ::max(f[i-1][j-1] + 1, ::max(f[i][j-1], f[i-1][j]));
                } else {
                    f[i][j] = ::max(f[i][j-1], f[i-1][j]);
                }
            }
        }
        // answer
        return f[lenA][lenB];
        
    }
};

