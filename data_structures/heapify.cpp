class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void siftup(vector<int> &A, int i) {
        while (i != 0) {
            int father = (i-1) / 2;
            if (A[father] < A[i]) break;
            
            int tmp = A[father];
            A[father] = A[i];
            A[i] = tmp;
            
            i = father;
        }
    }
    void heapify(vector<int> &A) {
        // write your code here
        for (int i = A.size() - 1; i >= 0; i--) {
            siftup(A, i);
        }
    }
};
