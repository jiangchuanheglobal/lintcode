class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int lastPosition(vector<int>& A, int target) {
        // Write your code here
        if (A.size() == 0) return -1;
        int start, end;
        start = 0;
        end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (target >= A[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (A[end] == target) {
            return end;
        } else if (A[start] == target) {
            return start;
        }
        
        return -1;
    }
};
