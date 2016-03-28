class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        for (int i = 0; i < A.size(); i++) {
            
            while (A[i] > 0 &&
                  A[i] < A.size() &&
                  A[i] != i + 1 &&
                  A[A[i] - 1] != A[i]) {
                      int tmp = A[A[i] - 1];
                      A[A[i] - 1] = A[i];
                      A[i] = tmp;
                  }
        }
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return A.size() + 1;
    }
};
