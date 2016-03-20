class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        string prefix = "";
        for (int i = 0; i < strs.size(); i++) {
            if (i == 0) {
                prefix = strs[i];
            } else {
                prefix = getCommonPrefix(strs[i], prefix);
            }
        }
        return prefix;
    }
    
    string getCommonPrefix(string& s1, string& s2) {
        int i = 0;
        while (i < s1.length() && i < s2.length() && s1[i] == s2[i]) {
            i += 1;
        }
        return s1.substr(0, i);
    }
};
