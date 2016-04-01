class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        map<int, int> mapping; // key: element, val: index
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (mapping.find(target - nums[i]) != mapping.end()) {
                result.push_back(mapping[target - nums[i]] + 1);
                result.push_back(i + 1);
                break;
            }
            mapping[nums[i]] = i;
        }
        
        return result;
    }
};
