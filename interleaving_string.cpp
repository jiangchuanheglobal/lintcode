class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        int lenS1 = s1.length();
        int lenS2 = s2.length();
        int lenS3 = s3.length();
        if (lenS3 != lenS1 + lenS2) return false;
        
        // define
        vector<vector<bool> > f(lenS1 + 1, vector<bool>(lenS2 + 1, false));
        
        // init
        f[0][0] = true;
        for (int i = 1; i <= lenS1; i++) {
            f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for (int j = 1; j <= lenS2; j++) {
            f[0][j] = f[0][j - 1] && s2[j - 1] == s3[j - 1];
        }
        
        // function
        for (int i = 1; i <= lenS1; i++) {
            for (int j = 1; j <= lenS2; j++) {
                if ( (f[i-1][j] && s1[i - 1] == s3[i + j - 1])
                    || (f[i][j-1] && s2[j - 1] == s3[i + j - 1]) ) {
                    f[i][j] = true;
                } else {
                    f[i][j] = false;
                }
            }
        }
        // answer
        return f[lenS1][lenS2];
    }
};
