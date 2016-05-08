class Solution {
public:
    /**
     * @param A an integer array
     * @param target an integer
     * @param k a non-negative integer
     * @return an integer array
     */
    vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
        // Write your code here
        vector<int> result;
        if (A.size() == 0) return result;
        if (k > A.size()) return result;
        
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
        
        while (k > 0 && start >= 0 && end <= A.size() - 1) {
            if (abs(A[start] - target) == abs(A[end] - target)) {
                result.push_back(A[start]);
                start -= 1;
            } else if ( abs(A[start] - target) < abs(A[end] - target) ) {
                result.push_back(A[start]);
                start -= 1;
            } else {
                result.push_back(A[end]);
                end += 1;
            }
            k -= 1;
        }
        
        if (k == 0) return result;
        if (start < 0) {
            while (k-- > 0) {
                result.push_back(A[end]);
                end += 1;
            }
        } else {
            while (k-- > 0) {
                result.push_back(A[start]);
                start -= 1;
            }
        }
        return result;
    }
};
