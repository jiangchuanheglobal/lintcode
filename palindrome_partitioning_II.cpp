class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    
    bool isPalindrome(vector<vector<bool>>& palinInfo, int start, int end) {
        return palinInfo[start][end];
    }
    
    void initPa(vector<vector<bool> >& pa, string& s) {
        //　区间型
        
        // init
        for (int i = 0; i < s.length(); i++) {
            pa[i][i] = true;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            pa[i][i+1] = s[i] == s[i+1];
        }
        
        for (int length = 2; length < s.length(); length ++) {
            for (int start = 0; start + length < s.length(); start++) {
                pa[start][start + length] = pa[start+1][start+length-1] 
                && s[start] == s[start + length];
            }
        }
    }
    
    int minCut(string s) {
        // write your code here
        
        // state
        vector<int> f(s.length() + 1);
        vector<vector<bool> > pa(s.length(), vector<bool>(s.length(), false));
        
        // init
        f[0] = -1;
        
        initPa(pa, s);
        // recursion
        for (int i = 1; i < s.size() + 1; i++) {
            f[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isPalindrome(pa, j, i-1)) {
                    f[i] = ::min(f[i], f[j] + 1);
                }
            }
        }
        
        // end
        return f[s.length()];
    }
};

