class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        // Write your code here
        if (s1.length() != s2.length()) return false;
        
        if (s1.compare(s2) == 0) return true;
        
        if (!isValid(s1, s2)) return false;
        
        int len = s1.length();
        for (int i = 0; i < len - 1; i++) {
            string s11 = s1.substr(0, i + 1);
            string s12 = s1.substr(i + 1, len - i - 1);
            string s21 = s2.substr(0, i + 1);
            string s22 = s2.substr(i + 1, len - i - 1);
            
            string s23 = s2.substr(0, len - i - 1);
            string s24 = s2.substr(len - i - 1, i + 1);
            
            //cout << s11 << "|" << s12 << "|" << s21 << "|" << s22 << "|" << s23 << "|" << s24 << endl;
             if (isScramble(s11, s21) && isScramble(s12, s22)) return true;
             if (isScramble(s11, s24) && isScramble(s12, s23)) return true;
        }
        return false;
    }
    
    bool isValid(string s1, string s2) {
        std::sort(s1.begin(), s1.end());
        std::sort(s2.begin(), s2.end());
        return s1.compare(s2) == 0;
    }
};

// rgeat -> great

// rg|eat  gr|eat   rg == gr && eat == eat

// rg|eat  gre|at   rg == at && eat == gre

// r geat

// [0, 0]
// (0, 1)

// [1, 4]
// (1, 4)

// "a" "a"

// s11 = "a"
// s12 = ""

// s21 = "a"
// s22 = ""

// s23 = ""
// s24 = "a"
