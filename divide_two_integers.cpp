class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if (divisor == 0) {
            return dividend > 0 ? INT_MAX : INT_MIN;
        }
        if (dividend == 0) {
            return 0;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int sign = 1;
        if (dividend > 0 && divisor < 0) {
            sign = -1;
        } else if (dividend < 0 && divisor > 0) {
            sign = -1;
        }
        
        long a = abs((long)dividend); // need long type, very tricky !!!
        long b = abs((long)divisor);

        int res = 0;
        while (a >= b) {
            int shift = 0;
            while (a >= (b << shift)) {
                shift += 1;
            }
            shift -= 1;
            
            a -= b << shift;
            res += 1 << shift;
        }
        return res * sign;
    }
    
};
