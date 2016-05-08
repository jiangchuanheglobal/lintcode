class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int start, end, mid;
        start = 0;
        end = A.size() - 1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid-1] > A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        return A[start] > A[end] ? start : end;
    }
};
