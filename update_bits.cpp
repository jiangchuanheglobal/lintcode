class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits(int n, int m, int i, int j) {
        // write your code here
        for (int k = i; k <= j; k++) {
            if ( m & (1 << (k - i)) ) {
                // set
                setBit(n, k);
                
            } else {
                // clear
                clearBit(n, k);
            }
        }
        return n;
    }
    
    void setBit(int& num, int pos) {
        num |= 1 << pos;
    }
    
    void clearBit(int& num, int pos) {
        num &= ~(1 << pos);
    }
};
