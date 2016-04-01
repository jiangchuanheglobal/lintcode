class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        // write your code here
        int k = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >=0) {
                A[k] = A[i] >= B[j] ? A[i--] : B[j--];
            } else if (i >= 0) {
                A[k] = A[i--];
            } else {
                A[k] = B[j--];
            }
            k -= 1;
        }
    }
};
