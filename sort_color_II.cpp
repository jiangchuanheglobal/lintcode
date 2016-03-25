class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int start = 0;
        int end = colors.size() - 1;
        
        while (start <= end) {
            int largest = findLargest(start, end, colors);
            int smallest = findSmallest(start, end, colors);
            
            sortColors1(start, end, largest, smallest, colors);
        }
    }
    
    void sortColors1(int& start, int& end, int largest, int smallest, vector<int> &nums) {
        // write your code here
        int i = end;
        
        while (start <= i) {
            if (nums[i] == smallest) {
                swap(nums, start, i);
                start += 1;
            } else if (nums[i] == largest) {
                swap(nums, i, end);
                end -= 1;
                i -= 1;
            } else {
                i -= 1;
            }
        }
    }
    
    int findLargest(int start, int end, vector<int>& nums) {
        int ans = INT_MIN;
        for (int i = start; i <= end; i++) {
            ans = ::max(ans, nums[i]);
        }
        return ans;
    }
    
    int findSmallest(int start, int end, vector<int>& nums) {
        int ans = INT_MAX;
        for (int i = start; i <= end; i++) {
            ans = ::min(ans, nums[i]);
        }
        return ans;
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
