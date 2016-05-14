class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<int> result;
        if (nums.size() == 0) return result;
        
        vector<int> presum(nums.size() + 1);
        presum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            presum[i + 1] = presum[i] + nums[i];
        }
        
        // two sum
        map<int, int> mapping;
        for (int i = 0; i < presum.size(); i++) {
            if (mapping.find(presum[i]) != mapping.end()) {
                result.push_back(mapping[presum[i]] + 1);
                result.push_back(i - 1);
                return result;
            }
            mapping[presum[i]] = i - 1;
        }
        
        std::sort(presum.begin(), presum.end());
        
        // compete
        int lastDiff = INT_MAX;
        for (int i = 0; i < presum.size() - 1; i++) {
            int diff = abs(presum[i] - presum[i + 1]);
            if ( diff <= lastDiff) {
                lastDiff = diff;
                result.clear();
                result.push_back(mapping[presum[i]]);
                result.push_back(mapping[presum[i + 1]]);
            }
        }
        
        std::sort(result.begin(), result.end());
        
        result[0] += 1;
        return result;
    }
};
