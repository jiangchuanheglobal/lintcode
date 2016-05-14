class Solution {
public:    
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        // write your code here
        vector<char> tar(256, 0);
        vector<char> sor(256, 0);
        
        initHash(tar, target);
        int fast = 0;
        string ans = source;
        int len = INT_MAX;
        for (int slow = 0; slow < source.length(); slow++) {
            while (fast < source.length() && !valid(sor ,tar)) {
                sor[source[fast]] += 1;
                fast += 1;
            }
            
            if (valid(sor, tar)) {
                if (len > fast - slow) {
                    ans = source.substr(slow, fast - slow);
                    len = fast - slow;
                }
            }
            sor[source[slow]] -= 1;
        }
        
        return len == INT_MAX ? "" : ans;
    }
    
    void initHash(vector<char>& tar, string& target) {
        int tar_len = target.size();
        for (int i = 0; i < tar_len; i++) {
            tar[target[i]] += 1;
        }
    }   
    
    bool valid(vector<char>& src_hash, vector<char>& tar_hash) {
        for (int i = 0; i < 256; i++) {
            if (src_hash[i] < tar_hash[i]) return false;
        }
        return true;
    }
};
