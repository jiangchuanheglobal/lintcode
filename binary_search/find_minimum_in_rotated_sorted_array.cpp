class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int start, end;
        int mid;
        start = 0;
        end = num.size() - 1;
        
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (num[mid] <= num[end]) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        return num[start] < num[end] ? num[start] : num[end];
    }
};
