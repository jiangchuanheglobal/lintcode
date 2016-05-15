class TrieNode {
  public: 
  TrieNode():label(0), wordEnd(false) {}
  TrieNode(char l, bool e): label(l), wordEnd(e) {}
  char label;
  bool wordEnd;
  map<char, TrieNode> children;
};

class Trie {
  public:
  void add(string& word) {
      TrieNode* curt = &dummyHead;
      for (auto& c : word) {
          if (curt->children.find(c) == curt->children.end()) {
              curt->children[c] = TrieNode(c, false);
          }
          curt = &curt->children[c];
      }
      curt->wordEnd = true;
  }
  TrieNode dummyHead;
};

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    void helper(vector<vector<bool>>& visit, vector<vector<char> > & board,
    int i, int j, TrieNode& root, string& word, vector<string>& result) {
        int m = board.size();
        int n = board[0].size();
        if ( i < 0 || i >= m || j < 0 || j >= n) return;
        if (visit[i][j]) return;
        
        for (auto it = root.children.begin(); it != root.children.end(); it++) {
            char label = it->first;
            TrieNode& child = it->second;
            if (label != board[i][j]) continue;
            
            word.push_back(label);
            visit[i][j] = true;
            if (child.wordEnd) {
                result.push_back(word);
                child.wordEnd = false; // an ugly way to prevent duplicate
            }
            helper(visit, board, i-1, j, child, word, result);
            helper(visit, board, i+1, j, child, word, result);
            helper(visit, board, i, j-1, child, word, result);
            helper(visit, board, i, j+1, child, word, result);
            word.pop_back();
            visit[i][j] = false;
        }
    }
    
    vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
        // write your code here
        vector<string> result;
        if (board.size() == 0) return result;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        Trie trie;
        string word;
        // construct trie
        for (auto& word : words) {
            trie.add(word);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                helper(visit, board, i, j, trie.dummyHead, word, result);
            }
        }
        
        return result;
    }
