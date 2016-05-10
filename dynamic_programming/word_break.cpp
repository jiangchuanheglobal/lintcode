class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string> &dict) {
        // write your code here
        int len = s.length();
        // define
        vector<bool> f(len + 1, false);
        
        int wordMin = INT_MAX; 
        int wordMax = INT_MIN;
        for (auto& str : dict) {
            wordMin = ::min(wordMin, (int)str.length());
            wordMax = ::max(wordMax, (int)str.length());
        }
        
        // init
        f[0] = true;
        
        // function
        for (int i = 1; i <= len; i++) {
            for (int j = i - wordMin; j >= i - wordMax && j >= 0; j--) {
                if (f[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[len];
    }
};
