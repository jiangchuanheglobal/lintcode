class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        
        // define
        // f[i][j]
        int lenS = S.length();
        int lenT = T.length();
        
        vector<vector<int> > f(lenS + 1, vector<int>(lenT + 1, 0));
        
        // init
        for (int i = 0; i <= lenS; i++) {
            f[i][0] = 1;
        }
        for (int i = 1; i <= lenT; i++) {
            f[0][i] = 0;
        }
        
        // function
        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenT; j++) {
                if (S[i - 1] == T[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
        // answer
        return f[lenS][lenT];
    }
};
