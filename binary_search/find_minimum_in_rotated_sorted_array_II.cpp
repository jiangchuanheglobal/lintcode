class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int min = INT_MAX;
        for (int i = 0; i < num.size(); i++) {
            min = ::min(min, num[i]);
        }
        return min;
    }
};
