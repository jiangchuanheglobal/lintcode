
class Pair {
  public:
  Pair(string w, int c) {
      word = w;
      counts = c;
  }
  Pair(const Pair& p) {
      word = p.word;
      counts = p.counts;
  }
  int counts;
  string word;
};

class MyComparator {
public:
    bool operator()(Pair p1, Pair p2) {
        if (p1.counts != p2.counts)
            return p1.counts >= p2.counts;
        else 
            return p1.word < p2.word;
    }
};

class Solution {
public:
    /**
     * @param words an array of string
     * @param k an integer
     * @return an array of string
     */
    vector<string> topKFrequentWords(vector<string>& words, int k) {
        // Write your code here
        vector<string> result;
        if (words.size() == 0) return result;
        
        map<string, int> wdcnts;
        for (int i = 0; i < words.size(); i++) {
            if (wdcnts.find(words[i]) == wdcnts.end()) {
                wdcnts[words[i]] = 0;
            }
            wdcnts[words[i]] += 1;
        }
        
        
        priority_queue<Pair, vector<Pair>, MyComparator> pq;
        for (auto it = wdcnts.begin(); it != wdcnts.end(); it++) {
            pq.push(Pair(it->first, it->second));
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            result.push_back(pq.top().word);
            pq.pop();
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

// 统计频数
// 创建min heap
// 放入heap，维持heap的size为k
// 取出heap中元素, 按要求输出
