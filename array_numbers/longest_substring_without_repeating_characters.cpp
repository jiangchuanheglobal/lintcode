class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        int ans = 0;
        int fast, slow;
        vector<bool> exist(false, 256);
        // fast outside
        for (fast = 0; fast < s.length(); fast++) {
            while (slow < fast && exist[s[fast]]) {
                exist[s[slow]] = false;
                slow += 1;
            }
            
            ans = ::max(ans, fast - slow + 1);
            exist[s[fast]] = true;
        }
        return ans;
    }
};
