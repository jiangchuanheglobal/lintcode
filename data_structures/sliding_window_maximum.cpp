class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        
        std::deque<int> deq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            
            while (!deq.empty() && deq.back() < nums[i]) {
                deq.pop_back();
            }
            deq.push_back(nums[i]);
            
            if (i >= k) {
                if (deq.front() == nums[i-k]) {
                    deq.pop_front();
                }
            }
            if (i >= k - 1) {
                res.push_back(deq.front());
            }
        }
        return res;
    }
};
