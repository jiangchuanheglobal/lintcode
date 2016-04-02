class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        // write your code here
        int len1 = word1.length();
        int len2 = word2.length();
        
        // define
        vector<vector<int> > f(len1 + 1, vector<int>(len2 + 1, 0));
        // init
        for (int i = 0; i <= len1; i++) {
            f[i][0] = i;
        }
        
        for (int j = 0; j <= len2; j++) {
            f[0][j] = j;
        }
        
        // function
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = ::min(f[i-1][j-1], ::min(f[i-1][j] + 1, f[i][j-1] + 1));
                } else {
                    f[i][j] = ::min(f[i-1][j-1] + 1, ::min(f[i-1][j] + 1, f[i][j-1] + 1));
                }
            }
        }
        // answer
        return f[len1][len2];
    }
};
