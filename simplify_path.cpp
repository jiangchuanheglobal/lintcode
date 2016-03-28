class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        
        vector<string> stubs = split(path, '/');
        vector<string> paths;
        for (auto& s : stubs) {
            if (s.compare("..") == 0) {
                if (!paths.empty()) {
                    paths.pop_back();
                }
            } else if (s.compare(".") != 0 && s.compare("") != 0) {
                paths.push_back(s);
            }
        }
        
        if (paths.empty()) {
            paths.push_back("");
        }
        
        string ans = "";
        for (auto& p : paths) {
            ans += "/" + p;
        }
        return ans;
    }
    
    vector<string> split(string str, const char sp) {
        vector<string> strings;
        istringstream f(str);
        string s;    
        while (getline(f, s, sp)) {
            // cout << s << endl;
            strings.push_back(s);
        }
        return strings;
    }
};
