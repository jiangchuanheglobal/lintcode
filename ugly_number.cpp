class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        // Write your code here
        vector<int> ugly{2, 3, 5};
        
        for (auto& n : ugly) {
            while (num % n == 0 && num != 0) {
                num /= n;
            }
        }
        
        return num == 1;
    }
};
