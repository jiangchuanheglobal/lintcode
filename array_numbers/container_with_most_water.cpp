class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        // write your code here
        int left = 0;
        int right = heights.size() - 1;
        
        int water = 0;
        while (left <= right) {
            
            water = ::max(water, (right - left) * (heights[left] < heights[right] ? heights[left] : heights[right]));
            
            if (heights[left] < heights[right]) {
                left += 1;
            } else {
                right -= 1;
            }
        }
        
        return water;
    }
};
