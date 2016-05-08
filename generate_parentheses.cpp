class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> ans;
        string s = "";
        DFS(ans, s, 0, 0, n);
        return ans;
    }
    
    void DFS(vector<string>& result, string path, int left, int right, int n) {
        if (path.size() == n*2) {
            result.push_back(path);
            return;
        }
        if (left < n) {
            DFS(result, path + "(", left + 1, right, n);
        }
        if (right < left) {
            DFS(result, path + ")", left, right + 1, n);
        }
    }
};

//   (
//  (   )
// ( )  ( )

// left, right

// append left, if left < n

// append right if right < left
