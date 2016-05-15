
class Block {
  public:
  Block(int x, int y, int height) {
      this->x = x;
      this->y = y;
      this->height = height;
  }
  Block(const Block& b) {
      x = b.x;
      y = b.y;
      height = b.height;
  }
  int height;
  int x; // row
  int y; // col
};

class MyComparator {
  public:
    bool operator()(Block b1, Block b2) {
        return b1.height >= b2.height;
    }
};

class Solution {
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        int m = heights.size(); // rows
        if (m == 0) return 0;
        
        int n = heights[0].size(); // cols
        std::priority_queue<Block, vector<Block>, MyComparator> pq;
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        // init pq
        for (int i = 0; i < m; i++) { // left edge col, right edge col
            pq.push(Block(i, 0, heights[i][0]));
            pq.push(Block(i, n - 1, heights[i][n - 1]));
            visit[i][0] = true;
            visit[i][n-1] = true;
        }
        for (int i = 0; i < n; i++) { // up edge row, down edge row
            pq.push(Block(0, i, heights[0][i]));
            pq.push(Block(m - 1, i, heights[m - 1][i]));
            visit[0][i] = true;
            visit[m - 1][i] = true;
        }
        
        int water = 0;
        int last_shortest_block_height = 0;
        // main loop to computer the water
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        while (!pq.empty()) {
            Block b = pq.top();
            pq.pop();
            last_shortest_block_height = ::max(last_shortest_block_height, b.height);
            water += last_shortest_block_height - b.height;
            for (int i = 0; i < 4; i++) {
                int row = b.x + dx[i];
                int col = b.y + dy[i];
                if (row >= 0 && row < m && col >= 0 && col < n
                && !visit[row][col]) {
                    visit[row][col] = true;
                    pq.push(Block(row, col, heights[row][col]));
                }
            }
        }
        return water;
    }
};


