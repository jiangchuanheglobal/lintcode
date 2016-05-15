class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string>> result;
        vector<string> path;
        DFS(result, path, 0, s);
        return result;
    }
    
    void DFS(vector<vector<string>>& result,vector<string>& path, int pos, string& s) {
        if (pos == s.length()) {
            result.push_back(path);
            return;
        }
        
        for (int i = pos + 1; i <= s.length(); i++) {
            if (isPartition(s.substr(pos, i - pos))) {
                path.push_back(s.substr(pos, i - pos));
                DFS(result, path, i, s);
                path.pop_back();
            }
        }
        
    }
    
    bool isPartition(const string& s) {
        int i = 0;
        int j = s.length() - 1;
        while (i <=j) {
            if (s[i] != s[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};


// define:
// DFS: 搜索以path作为前缀， pos位置作为第一个字符， 的所有palindrome partitioning, 并把结果放在result中

//      aab
//  a|ab       aa|b  aab
 
//  a|a|b  


//       []
//   a
 // void DFS(result, path, pos, s)
 
 
