class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int i = 0;
        int j = 0;
        vector<int> result;
        while (i < A.size() || j < B.size()) {
            if (i < A.size() && j < B.size()) {
                if (A[i] <= B[j] ) {
                    result.push_back(A[i++]);
                } else {
                    result.push_back(B[j++]);
                }
            } else if (i < A.size()) {
                result.push_back(A[i++]);
            } else {
                result.push_back(B[j++]);
            }
        }
        
        return result;
    }
};
