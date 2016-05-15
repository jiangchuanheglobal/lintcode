
class Edge {
  public:
  Edge(int pos, int height, bool isStart) {
      this->pos = pos;
      this->height = height;
      this->isStart = isStart;
  }
  Edge(const Edge& e) {
      pos = e.pos;
      height = e.height;
      isStart = e.isStart;
  }
  int pos;
  int height;
  bool isStart;
};

struct Myclass {
  bool operator()(Edge e1, Edge e2) {
      if (e1.pos != e2.pos) {
          return e1.pos < e2.pos;
      }
      if (e1.isStart && e2.isStart) {
          return e1.height > e2.height;
      }
      if (!e1.isStart && !e2.isStart) {
          return e1.height < e2.height; // here must be '<' operator
      }
      return e1.isStart;
  }  
}MyEdgeComparator;

struct MyHeightComparator {
  bool operator()(int a, int b) {
      return a > b;
  }  
};

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        // write your code here
        
        // create edges array
        vector<Edge> edges;
        for (int i = 0; i < buildings.size(); i++) {
            edges.push_back(Edge(buildings[i][0], buildings[i][2], true));
            edges.push_back(Edge(buildings[i][1], buildings[i][2], false));
        }
        
        std::sort(edges.begin(), edges.end(), MyEdgeComparator);
        // iterate edges array, update pq
        // write outlines
        std::map<int, int, MyHeightComparator> pq;
        vector<vector<int> > outlines;
        int last_height_start_pos = -1;
        int last_height = 0;
        for (int i = 0; i < edges.size(); i++) {
            Edge& e = edges[i];
            if (e.isStart) {
                if (pq.find(e.height) == pq.end()) {
                    pq[e.height] = 0;
                }
                pq[e.height] += 1;
            } else {
                pq[e.height] -= 1;
                if (pq[e.height] == 0) {
                    pq.erase(e.height);
                }
            }
         
            if (last_height_start_pos == -1) {
                last_height_start_pos = e.pos;
                last_height = e.height;
            } else if (pq.empty()) {
                vector<int> outline;
                outline.push_back(last_height_start_pos);
                outline.push_back(e.pos);
                outline.push_back(last_height);
                outlines.push_back(outline);
                
                last_height_start_pos = -1;
                last_height = 0;
            } else if (!pq.empty() && pq.begin()->first != last_height) {
                vector<int> outline;
                outline.push_back(last_height_start_pos);
                outline.push_back(e.pos);
                outline.push_back(last_height);
                outlines.push_back(outline);
                
                last_height_start_pos = e.pos;
                last_height = pq.begin()->first;
            }
        }
        
        return outlines;
    }
};




