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
        vector<bool> vis(n + 1, false);
        vector<int> f(n + 1, 0);
        int max_a = memory_search(n, values, vis, f);
        return max_a > total / 2;
    }
    
    int memory_search(int i, vector<int>& values, vector<bool>& vis, vector<int>& f) {
        if (vis[i]) {
            return f[i];
        }
        int n = values.size();
        if (i == 0) {
            vis[0] = true;
            f[0] = 0;
            return 0;
        }
        if (i == 1) {
            vis[1] = true;
            f[1] = values[n - 1];
            return f[1];
        }
        if (i == 2) {
            vis[2] = true;
            f[2] = values[n - 1] + values[n - 2];
            return f[2];
        }
        if (i == 3) {
            vis[3] = true;
            f[3] = values[n - 3] + values[n - 2];
            return f[3];
        }
        if (i == 4) {
            vis[4] = true;
            f[4] = ::min( memory_search(i - 2, values, vis, f), memory_search(i - 3, values, vis, f) ) + values[n - 4];
            return f[4];
        }
       
        f[i] = ::max(::min( memory_search(i - 2, values, vis, f), memory_search(i - 3, values, vis, f) ) + values[n - i], 
        ::min( memory_search(i - 3, values, vis, f), memory_search(i - 4, values, vis, f) ) + values[n - i] + values[n - i + 1]);
        vis[i] = true;
        return f[i];
    }
    
};
