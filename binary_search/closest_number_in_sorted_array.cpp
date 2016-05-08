class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int closestNumber(vector<int>& A, int target) {
        if (A.size() == 0) return 0;
        // Write your code here
        int start, end;
        start = 0;
        end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (target <= A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        return abs(A[start] - target) <= abs(A[end] - target) ? start : end;
    }
};
