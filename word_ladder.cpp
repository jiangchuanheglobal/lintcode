class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        set<string> visited;
        queue<string> que;
        int shortest = 0;
        
        visited.insert(start);
        que.push(start);
        
        while (!que.empty()) {
            int size = que.size();
            shortest += 1;
            for (int i = 0; i < size; i++) {
                string word = que.front();
                que.pop();
                
                for (int i = 0; i < word.length(); i++) {
                    for (int c = 'a'; c <= 'z'; c++) {
                        if (word[i] == c) continue;
                        
                        string nextWord = word;
                        nextWord[i] = c;
                        
                        if (nextWord == end) return shortest + 1;
                        
                        if (dict.find(nextWord) != dict.end()) {
                            if (visited.find(nextWord) == visited.end()) {
                                que.push(nextWord);
                                visited.insert(nextWord);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }
};
