class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int totalOccurrence(vector<int>& A, int target) {
        // Write your code here
        if (A.size() == 0) return 0;
        // the same with find range
        
        // first appear target
        int start, end, first, last;
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
        if (A[start] == target) {
            first = start;
        } else if (A[end] == target) {
            first = end;
        } else {
            first = -1;
        }
        
        if (first == -1) return 0;
        
        // last appear target
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
            last = end;
        } else {
            last = start;
        }
        return last - first + 1;
    }
};
