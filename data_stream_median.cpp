class MyComparator1 {
   public:
   bool operator()(int a, int b) {
       return a >= b; // min heap
   }
};

class MyComparator2 {
    public:
    bool operator()(int a, int b) {
       return a <= b; // max heap
   }
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> result;
        std::priority_queue<int, vector<int>, MyComparator1> min_heap;
        std::priority_queue<int, vector<int>, MyComparator2> max_heap;
        
        int len = nums.size();
        int mid;
        for (int i = 0; i < len; i++) {
            // mid
            if (i == 0) {
                mid = nums[i];
            } else if (nums[i] >= mid) {
                min_heap.push(nums[i]);
            } else {
                max_heap.push(nums[i]);
            }
            
            if (max_heap.size() + 1 < min_heap.size()) {
                // take min number from right part
                int min_right = min_heap.top();
                min_heap.pop();
                max_heap.push(mid);
                mid = min_right;
            } else if (max_heap.size() > min_heap.size()) {
                int max_left = max_heap.top();
                max_heap.pop();
                min_heap.push(mid);
                mid = max_left;
            }
            result.push_back(mid);
        }
        return result;
    }
};







