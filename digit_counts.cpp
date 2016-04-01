class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int cnt = 0;
        for (int i = 0; i <= n; i++) {
            cnt += numDigitK(i, k);
        }
        return cnt;
    }
    
    int numDigitK(int n, int k) {
        if (n == 0 && k == 0) return 1;
        
        int cnt = 0;
        while ( n ) {
            if (n % 10 == k) cnt += 1;
            n = n / 10;
        }
        return cnt;
    }
};
