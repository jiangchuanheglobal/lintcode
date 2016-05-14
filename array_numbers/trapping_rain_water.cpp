class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
       	if (heights.size() == 0) return 0;

    	int water = 0;
    	int maxIndex;
    	int maxHeight = 0;
    	// find the max height
    	for (int i = 0; i < heights.size(); i++) {
    		if (heights[i] > maxHeight) {
    			maxIndex = i;
    			maxHeight = heights[i];
    		}
    	}
    	// from left end to max pivot
    	int maxLevel = 0;
    	for (int i = 0; i < maxIndex; i++) {
    		maxLevel = ::max(maxLevel, heights[i]);
    		water += maxLevel - heights[i];
    	}
    	// from right end to max pivot
    	maxLevel = 0;
    	for (int j = heights.size() - 1; j > maxIndex; j--) {
    		maxLevel = ::max(maxLevel, heights[j]);
    		water += maxLevel - heights[j];
    	}
    	// end
    	return water;
    }
};
