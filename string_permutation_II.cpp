class Solution {
public:
    /**
     * @param str a string
     * @return all permutations
     */
    vector<string> stringPermutation2(string& str) {
        // Write your code here
        vector<string> result;
        vector<bool> vis(str.length(), false);
        string path = "";
        
        std::sort(str.begin(), str.end());
        DFS(result, path, vis, str);
        return result;
    }
    
    void DFS(vector<string>& result, string& path, vector<bool>& vis, string& str) {
        if (path.length() == str.length()) {
            result.push_back(path);
            return;
        }
        
        for (int i = 0; i < str.length(); i++) {
            if (canTake(i, str, vis)) {
                vis[i] = true;
                path.push_back(str[i]);
                DFS(result, path, vis, str);
                path.pop_back();
                vis[i] = false;
            }
        }
    }
    
    bool canTake(int i, string& str, vector<bool>& vis) {
        if (i > 0 && str[i - 1] == str[i] && !vis[i - 1]) {
            return false;
        } else if (vis[i]) {
            return false;
        } else {
            return true;
        }
    }
