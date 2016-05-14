class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        long long start = 1;
        long long end = x;
        while (start + 1 < end) {
            long long mid = start + (end - start) / 2;
            if (mid*mid <= x) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (end*end < x) return end;
        else return start;
    }
};
// [1, x]


// last number which number*number < x

// jiuzhang template
