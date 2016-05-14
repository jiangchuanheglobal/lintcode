class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        // Write your code here
        vector<char> ss;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'A' && s[i] <= 'z') {
                if (s[i] >= 'A' && s[i] <= 'Z') {
                    ss.push_back(s[i]);
                } else {
                    ss.push_back(s[i] - ('a' - 'A'));
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
                ss.push_back(s[i]);
            }
        }
        
        int start = 0;
        int end = ss.size() - 1;
        while (start < end) {
            if (ss[start] != ss[end]) return false;
            start += 1;
            end -= 1;
        }
        return true;
    }
};
