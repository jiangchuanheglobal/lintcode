class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // write your code here
        vector<vector<string>> ladders;
        vector<string> path;
        map<string, vector<string>> graph;
        map<string, int> distance;
        
        BFS(graph, distance, start, end, dict);
        path.push_back(start);
        DFS(ladders, path, graph, distance, start, end);
        return ladders;
    }
    
    void BFS(map<string, vector<string>>& graph, map<string, int>& distance, string start, string end,
    unordered_set<string>& dict) {
        
        queue<string> que;
        set<string> visited;
        
        
        
        que.push(start);
        visited.insert(start);
        distance[start] = 0;
        distance[end] = INT_MAX;
        
        while (!que.empty()) {
            
            int size = que.size();
            
            for (int i = 0; i < size; i++) {
                string w = que.front();
                que.pop();
                for (int j = 0; j < w.size(); j++) {
                    for (int c = 'a'; c <= 'z'; c++) {
                        
                        string nextWord = w;
                        nextWord[j] = c;
                        
                        if (nextWord == end) {
                            distance[end] = ::min(distance[end], distance[w] + 1);
                        }
                        
                        if (dict.find(nextWord) != dict.end()) {
                            graph[w].push_back(nextWord);
                            if (visited.find(nextWord) == visited.end()) {
                                que.push(nextWord);
                                distance[nextWord]  = distance[w] + 1;
                                visited.insert(nextWord);
                            }
                        }
                    }
                }
            }
        }
    }
    
    void DFS(vector<vector<string>>& ladders, vector<string>& path, map<string, vector<string>>& graph, map<string, int>& distance, string start, string end) {
        if (start == end) {
            ladders.push_back(path);
            return;
        }
        
        if (distance[start] > distance[end]) return;
        
        for (auto& w : graph[start]) {
            if (distance[w] == distance[start] + 1) {
                path.push_back(w);
                DFS(ladders, path, graph, distance, w, end);
                path.pop_back();
            }
        }
    }
