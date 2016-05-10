class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // write your code here
        if (!s || !p) return false;
        
        int s_len = strlen(s);
        int p_len = strlen(p);
        
        bool f[s_len + 1][p_len + 1];
        f[0][0] = true;
        
        for (int i = 1; i <= s_len; i++) {
            f[i][0] = false;
        }
        
        for (int i = 1; i <= p_len; i++) {
            f[0][i] = f[0][i - 1] && p[i - 1] == '*';
        }
        
        for (int i = 1; i <= s_len; i++) {
            for (int j = 1; j <= p_len; j++) {
                if (p[j - 1] == '*') {
                    f[i][j] = f[i - 1][j] || f[i][j - 1];
                } else if (p[j - 1] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1];
                }
            }
        }
        
        return f[s_len][p_len];
    }
};
