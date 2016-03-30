class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        if (A.length() < B.length()) return false;
        
        map<char, int> cnt; 
        for (auto& b : B) {
            if (cnt.find(b) == cnt.end()) {
                cnt[b] = 0;
            }
            cnt[b] += 1;
        }
        
        for (auto& a : A) {
            if (cnt.find(a) != cnt.end()) {
                cnt[a] -= 1;
                if (cnt[a] == 0) {
                    cnt.erase(a);
                }
            }
        }
        return cnt.empty() ? true : false;
    }
};
