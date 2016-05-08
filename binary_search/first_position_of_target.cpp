class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if (array.size() == 0) return -1;
        int start, end, mid;
        start = 0;
        end = array.size() - 1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (target <= array[mid]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (target == array[start]) return start;
        if (target == array[end]) return end;
        return -1;
    }
};
