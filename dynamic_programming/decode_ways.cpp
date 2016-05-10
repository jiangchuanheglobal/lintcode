class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        // Write your code here
        int n = s.length();
        if (n == 0) return 0;
        
        vector<int> f(n + 1, 0);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            f[i] = 0;
            if (canDecodeLast(s, i - 1)) {
                f[i] += f[i - 1];
            }
            if (canDecodeLastTwo(s, i - 1)) {
                f[i] += f[i - 2];
            }
        }
        return f[n];
    }

    bool canDecodeLast(string& s, int i) {
        if (s[i] >= '1' && s[i] <= '9') {
            return true;
        } else {
            return false;
        }
    }
    
    bool canDecodeLastTwo(string& s, int i) {
        if (i < 1) return false;

        if (s[i - 1] == '1' && s[i] >= '0' && s[i] <= '9') {
            return true;
        } else if (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6') {
            return true;
        } else {
            return false;
        }
    }
};
