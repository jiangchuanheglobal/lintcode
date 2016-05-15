
class TrieNode {
  public:
  TrieNode():wordEnd(false) {
  }
  TrieNode(const TrieNode& node) {
      wordEnd = node.wordEnd;
      label = node.label;
      children = node.children;
  }
  TrieNode(bool w, char l) {
      wordEnd = w;
      label = l;
  }
  bool wordEnd;
  char label;
  map<char, TrieNode> children;
};

class Trie {
  public:
  void add(string word) {
      if (word.length() == 0) return;
      
      TrieNode *curt = &dummyHead;
      for (auto& c : word) {
          if (curt->children.find(c) == curt->children.end()) {
            curt->children[c] = TrieNode(false, c);
          }
          curt = &curt->children[c];
      }
      curt->wordEnd = true;
  }
  bool search(string word) {
      return searchHelper(dummyHead, word, 0);
  }
  bool searchHelper(TrieNode& curt, string& word, int pos) {
      if (word.size() == 0) {
          return true;
      }
      if (word[pos] != '.') {
          if (curt.children.find(word[pos]) == curt.children.end()) return false;
          if (pos + 1 == word.size()) return curt.children[word[pos]].wordEnd;
          
          return searchHelper(curt.children[word[pos]], word, pos+1);
      } else {
          for (auto it = curt.children.begin(); it != curt.children.end(); it++) {
              if (pos + 1 == word.size() && it->second.wordEnd) return true;
              if (pos + 1 != word.size() && searchHelper(it->second, word, pos+1)) return true;
          }
          return false;
      }
  }
  TrieNode dummyHead;
};


class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        trie.add(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return trie.search(word);
    }
    Trie trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
