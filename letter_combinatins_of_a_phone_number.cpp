class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        map<char, string> table;
        table['2'] = "abc";
        table['3'] = "def";
        table['4'] = "ghi";
        table['5'] = "jkl";
        table['6'] = "mno";
        table['7'] = "pqrs";
        table['8'] = "tuv";
        table['9'] = "wxyz";
        
        vector<string> result;
        
        if (digits.length() == 0) return result;
        
        string path = "";
        DFS(result, path, table, digits, 0);
        return result;
    }
    
    void DFS(vector<string>& result, string path, map<char, string>& table, string& digits, int pos) {
        if (path.length() == digits.length()) {
            result.push_back(path);
            return;
        }
        
        for (auto& c : table[digits[pos]]) {
            path.push_back(c);
            DFS(result, path, table, digits, pos + 1);
            path.pop_back();
        }
    }
};

// ""
