class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int m = A.size();
        int n = B.size();
        int len = m + n;
        if ( len % 2 == 0 ) {
            return ( helper(A, 0, B, 0, len/2) + helper(A, 0, B, 0, len/2 + 1) ) / 2;
        } else {
            return helper(A, 0, B, 0, len/2 + 1);
        }
    }
    
    double helper(vector<int>& A, int a_s, vector<int>& B, int b_s, int k) {
        if (b_s >= B.size()) {
            return A[a_s + k - 1];
        } else if (a_s >= A.size()) {
            return B[b_s + k - 1];
        } else if (k == 1) {
            return ::min(A[a_s], B[b_s]);
        }
        
        int drop = ::min((int)A.size() - a_s, ::min((int)B.size() - b_s, k/2));
        if (A[a_s + drop - 1] < B[b_s + drop - 1]) {
            return helper(A, a_s + drop, B, b_s, k - drop);
        } else {
             // drop B
            return helper(A, a_s, B, b_s + drop, k - drop);
        }
    }
};

