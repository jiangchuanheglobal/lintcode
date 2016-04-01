class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        vector<vector<int> > result;
        std::sort(nums.begin(), nums.end());
        int len = nums.size(); // size() return size_t type, nums.size() - 3 cause issue
        
        for (int i = 0; i < len - 3; i++) {
            if (i != 0 && nums[i - 1] == nums[i]) continue;
            
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j != i + 1 && nums[j - 1] == nums[j]) continue;
                
                int start = j + 1;
                int end = nums.size() - 1;
                
                while (start < end) {
                    if (start != j + 1 && nums[start - 1] == nums[start]) {
                        start += 1;
                        continue;
                    }
                    
                    int sum = nums[i] + nums[j] + nums[start] + nums[end];
                    if (sum == target) {
                        vector<int> quple;
                        quple.push_back(nums[i]);
                        quple.push_back(nums[j]);
                        quple.push_back(nums[start]);
                        quple.push_back(nums[end]);
                        result.push_back(quple);
                        start += 1;
                        end -= 1;
                    } else if (sum < target) {
                        start += 1;
                    } else {
                        end -= 1;
                    }
                }
            }
        }
        
        return result;
    }
};
