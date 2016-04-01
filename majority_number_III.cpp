class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
     
    void removeKey(map<int, int>& cnt) {
        for (auto it = cnt.begin(); it != cnt.end(); ) {
            it->second -= 1;
            if (it->second == 0) {
                cnt.erase(it++);
            } else {
                it++;
            }
        }
    }
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        // k - 1  candidates
        map<int, int> cnt;
        
        for (int i = 0; i < nums.size(); i++) {
            if (cnt.find(nums[i]) != cnt.end()) {
                cnt[nums[i]] += 1;
            } else {
                cnt[nums[i]] = 1;
            } 
            if (cnt.size() > k - 1) {
                removeKey(cnt);
            }
        }
        
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            it->second = 0;
        }
        
        int major = -1;
        int major_cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt.find(nums[i]) != cnt.end()) {
                cnt[nums[i]] += 1;
                if (major_cnt < cnt[nums[i]]) {
                    major_cnt = cnt[nums[i]];
                    major = nums[i];
                }
            }
        }
        return major;
    }
};
