class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        // write your code here
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (existPath(board, i, j, word, 0, visit)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool existPath(vector<vector<char>>&board, int i, int j, string& word, int pos, vector<vector<bool>>& visit) {
        if (pos == word.size()) return true;
        
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return false;
        }
        if (!visit[i][j] && board[i][j] == word[pos]) {
            visit[i][j] = true;
            if (existPath(board, i-1, j, word, pos+1, visit)) return true;
            if (existPath(board, i+1, j, word, pos+1, visit)) return true;
            if (existPath(board, i, j-1, word, pos+1, visit)) return true;
            if (existPath(board, i, j+1, word, pos+1, visit)) return true;
            visit[i][j] = false;
        } 
        return false;
    }
