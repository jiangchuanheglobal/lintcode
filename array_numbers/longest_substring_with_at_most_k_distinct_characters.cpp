class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        // write your code here
        
        vector<int> dist(256, 0);
        int ans = 0;
        int slow, fast;
        int cnt = 0;
        for (fast = 0, slow = 0; fast < s.length(); fast++) {
            if (dist[s[fast]]++ == 0) cnt += 1;
            while (cnt > k) {
                dist[s[slow]] -= 1;
                if (dist[s[slow++]] == 0) cnt -= 1;
            }
            
            ans = ::max(ans, fast - slow + 1);
        }
        
        return ans;
    }
};
