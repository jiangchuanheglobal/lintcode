class Solution {
public:
    /**
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    
    /**
     * character set
     * [0-9]
     * [.]
     * [+-]
     * [e]
     * [\s]
     */

    bool isNumber(string& s) {
        // Write your code here
        if (s.length() == 0) return false;
        
        int i = 0;
        int e = s.length() - 1;
        
        // removing leading space
        while (i <= e && s[i] == ' ') {
            i += 1;
        }
        // removing trailing space
        while (e >= i && s[e] == ' ') {
            e -= 1;
        }
        
        // all characters are spaces
        if (i > e) return false;
        
        if (s[i] == '+' || s[i] == '-') {
            i += 1;
        }
        
        bool dot = false;
        bool digit = false;
        bool expon = false;
        while (i <= e) {
            char c = s[i];
            
            if (c >= '0' && c <= '9') {
                digit = true;
            } else if (c == '.') {
                if (dot || expon) {
                    return false;
                } else {
                    dot = true;
                }
            } else if (c == 'e' || c == 'E') {
                if (expon || digit == false) {
                    return false;
                } else {
                    expon = true;
                    digit = false;
                }
            } else if (c == '+' || c == '-') {
                if (s[i - 1] != 'e' || s[i - 1] != 'E') {
                    return false;
                }
            } else {
                return false;
            }
            
            i += 1;
        }
        
        return digit;
    }
};
