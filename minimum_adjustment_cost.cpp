class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
        int n = A.size();
        vector<vector<bool> > vis(n, vector<bool>(100, false));
        vector<vector<int> > f(n, vector<int>(100, 0));
        
        int ans = INT_MAX;
        for (int i = 1; i <= 100; i++) {
            ans = ::min(ans, memory_search(n - 1, i, f, vis, A, target));
        }
        return ans;
    }
    
    int memory_search(int i, int j, vector<vector<int> >& f, vector<vector<bool> >& vis, vector<int>& A, int target) {
        if (vis[i][j]) {
            return f[i][j];
        }
        if (i == 0) {
            vis[i][j] = true;
            f[i][j] = abs(j - A[i]);
            return f[i][j];
        }
        
        int start = ::max(j - target, 0);
        int end = ::min(j + target, 100);
        
        f[i][j] = INT_MAX;
        for (int k = start; k <= end; k++) {
            f[i][j] = ::min(f[i][j], memory_search(i - 1, k, f, vis, A, target) + abs(j - A[i]));
        }
        vis[i][j] = true;
        return f[i][j];
    }
};



// // DFS(A, [], 0, target, MAX_INT)
// DFS(A, path, pos, target, minAdjust) {
//     if (pos == A.length()) {
//         mnAdjust = ::min(minAdjust, abs(A-path));
//         return;
//     }
    
//     for (int i = 1, i <= 100; i++) {
//         if (pos && path[pos] + i > 100 && path[pos] + i <= 0) {
//             continue;
//         }
//         path.push_back(path[pos] + i);
//         DFS(A, path, pos + 1, target, minAdjust);
//         path.pop_back();
//     }
// }

// f[i][j]

// // 返回以第i个位置，取j值开头的最小调整代价
// for (int i = 1; i <= 100; i++) {
//     minAdj = ::min(minAdj, compute(A, 0, target, f, i));
// }
// return minAdj;

// int compute(A, pos, val, target, f) {
//     if (pos > A.length()) return 0;
//     if (f[pos][val]) return f[pos][val];
    
//     int minAdj = INT_MAX;
//     for (int i = 1; i <= 100; i++) {
//         if (pos && abs(val - i) >= target) continue;
//         minAdj = ::min(minAdj, abs(i - A[pos]) + compute(A, pos + 1, i, target, f));
//     }
//     f[pos][val] = minAdj;
//     return f[pos][val];
