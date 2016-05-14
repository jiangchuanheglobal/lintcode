class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        
        vector<int> result;
        int preSum = 0;
        map<int, int> rep;
        rep[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            
            if (rep.find(preSum) != rep.end()) {
                result.push_back(rep[preSum] + 1);
                result.push_back(i);
                break;
            } 
            rep[preSum] = i;
        }
        return result;
    }
};
