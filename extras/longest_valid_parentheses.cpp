class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        vector<int> f(len, 0);
        
        for (int i = 1; i < len; i++) {
            if (s[i - 1] == '(' && s[i] == ')') {
                f[i] = 2;
            }
        }
        
        int max_len = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (f[i - 1] > 0) {
                    int j = i - f[i - 1] - 1;
                    if (j >= 0 && s[j] == '(') { // miss j >= 0
                        f[i] = f[i - 1] + 2;
                    }
                }
                if (f[i] > 0) {
                    int j = i - f[i];
                    if (j > 0 && f[j] > 0) {
                        f[i] = f[i] + f[j];
                    }
                }
            }
            max_len = ::max(max_len, f[i]);
        }
        return max_len;
    }
};
