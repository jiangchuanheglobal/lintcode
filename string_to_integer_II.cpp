class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
     
     
     /**
      * char set
      * [0-9]
      * [+-]
      * [.]
      * [\s]
      */
    
    int atoi(string str) {
        // write your code here
        
        int i = 0;
        
        // removing leading space
        while (i < str.length() && str[i] == ' ') {
            i += 1;
        }
        
        int sign = 1;
        if (str[i] == '-') {
            sign = -1;
            i += 1;
        } else if (str[i] == '+') {
            i += 1;
        }
        
        int num = 0;
        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            int tmp = num * 10 + str[i] - '0';
            
            if (tmp / 10 != num) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            
            num = tmp;
            i += 1;
        }
        
        return sign * num;
    }
};
