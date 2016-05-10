class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        
        int n = prices.size();
        
        if (k >= n) {
            return maxProfit2(prices);
        }
        vector<vector<int> > mustsell(n + 1, vector<int>(n + 1, 0));
        vector<vector<int> > globalbest(n + 1, vector<int>(n + 1, 0));
        
        // init
        
        
        // DP
        for (int i = 1; i <= n; i++) {
            int gain = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; j++) {
                mustsell[i][j] = ::max(globalbest[i - 1][j - 1] + ::max(gain, 0), mustsell[i - 1][j] + gain);
                globalbest[i][j] = ::max(globalbest[i - 1][j], mustsell[i][j]);
            }
        }
        
        return globalbest[n - 1][k]; // why n - 1 ?
    }
    
    int maxProfit2(vector<int> &prices) {
        // write your code here
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1]) {
                profit += prices[i] - prices[i-1];
            }
        }
        
        return profit;
    }
};
