class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        vector<bool> f(n + 1, false);
        vector<bool> vis(n + 1, false);
        
        return search(n, f, vis);
    }
    
    bool search(int n, vector<bool>& f, vector<bool>& vis) {
        if (vis[n]) {
            return f[n];
        }
        if (n == 0) {
            vis[0] = true;
            f[0] = false;
            return f[0];
        }
        if (n == 1) {
            vis[n] = true;
            f[1] = true;
            return f[1];
        }
        if (n == 2) {
            vis[n] = true;
            f[2] = true;
            return f[2];
        }
        if (n == 3) {
            vis[n] = true;
            f[3] = false;
            return f[3];
        }
        if (n == 4) {
            vis[n] = true;
            f[4] = true;
            return f[4];
        }
        vis[n] = true;
        f[n] = (search(n - 2, f, vis) && search(n - 3, f, vis)) ||
                (search(n - 3, f, vis) && search(n - 4, f, vis));
        return f[n];
    }
};
