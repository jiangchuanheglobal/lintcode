class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int total = 0;
        for (auto& v : values) {
            total += v;
        }
        
        int n = values.size();
        vector<vector<int> > f(n + 1, vector<int>(n + 1, 0));
        vector<vector<bool> > vis(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; i++) {
            vis[i][i] = true;
            f[i][i] = values[i - 1];
        }
        for (int i = 1; i < n; i++) {
            vis[i][i + 1] = true;
            f[i][i + 1] = ::max(f[i][i], f[i + 1][i + 1]);
        }
        int max_a = memory_search(1, n, f, vis);
        return max_a > total / 2;
    }
    int memory_search(int left, int right, vector<vector<int> >& f, vector<vector<bool> >&vis) {
        if (vis[left][right]) {
            return f[left][right];
        }
        vis[left][right] = true;
        f[left][right] = ::max( ::min(memory_search(left + 1, right - 1, f, vis), memory_search(left + 2, right, f, vis)) + f[left][left],
        ::min(memory_search(left + 1, right - 1, f, vis), memory_search(left, right - 2, f, vis)) + f[right][right]);
        
        return f[left][right];
    }
};
