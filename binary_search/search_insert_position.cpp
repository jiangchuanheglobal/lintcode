class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if (A.size() == 0) return 0;
        int start = 0;
        int end = A.size() - 1;
        int mid;
        
        while (start + 1 < end) {
            mid = start + (end-start)/2;
            if (A[mid] == target) {
                end = mid;
            } else if (A[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (target <= A[start]) return start;
        if (target <= A[end]) return end;

        // if (target < A[start]) return start;
        // if (target < A[end]) return end;
        return A.size();
    }
};
