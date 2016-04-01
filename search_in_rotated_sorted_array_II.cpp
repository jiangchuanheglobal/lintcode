class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == target) return true;
        }
        return false;
    }
};
