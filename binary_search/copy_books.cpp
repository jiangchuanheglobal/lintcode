class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        
        int size = pages.size();
        int max_time = 0;
        for (int i = 0; i < size; i++) {
            max_time += pages[i];
        }
        
        int start = 0;
        int end = max_time;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (canCopy(pages, mid, k)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (canCopy(pages, start, k)) {
            return start;
        } else {
            return end;
        }
    }
    
    bool canCopy(vector<int>& pages, int minute, int k) {
        int parts = 0;
        int size = pages.size();
        int slow = 0;
        int fast = 0;
        while (fast < size) {
            int sum = 0;
            slow = fast;
            while (fast < size && sum + pages[fast] <= minute) {
                sum += pages[fast];
                fast += 1;
            }
            if (slow == fast) return false;
            parts += 1;
        }
        return parts <= k;
    }
    
};
