class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        vector<int> result;
        if (A.size() == 0) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        
        int start, end, mid;
        start = 0;
        end = A.size() - 1;
        while (start + 1 < end) {
            mid = start + (end-start) / 2;
            if (target <= A[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (A[start] == target) {
            result.push_back(start);
        } else if (A[end] == target) {
            result.push_back(end);
        } else {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        start = start;
        end = A.size() - 1;
        while (start + 1 < end) {
            mid = start + (end-start) / 2;
            if (target >= A[mid]) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (A[end] == target) {
            result.push_back(end);
        } else {
            result.push_back(start);
        }
        return result;
    }
};
