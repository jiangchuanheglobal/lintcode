class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        // Write your code here
        int len = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<bool> > vis(len + 1, vector<bool>(len + 1, false));
        vector<vector<int> > f(len + 1, vector<int>(len + 1, 0));
        
        return memory_search(1, len, nums, f, vis);
    }
    
    int memory_search(int i, int j, vector<int>& A, vector<vector<int>>& f, vector<vector<bool>>& vis) {
        if (i > j) {
            return 0;
        }
        if (vis[i][j]) {
            return f[i][j];
        }
        
        for (int k = i; k <= j; k++) {
            f[i][j] = ::max(f[i][j], memory_search(i, k - 1, A, f, vis) + memory_search(k + 1, j, A, f, vis) +
            A[i - 1] * A[k] * A[j + 1]);
        }
        vis[i][j] = true;
        return f[i][j];
    }
};
