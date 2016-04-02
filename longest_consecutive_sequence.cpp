class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        // write you code here
        
        set<int> table;
        for (int i = 0; i < num.size(); i++) {
            table.insert(num[i]);
        }
        
        int longest = INT_MIN;
        for (int i = 0; i < num.size(); i++) {
            int n = num[i];
            int low = n - 1;
            while (table.find(low) != table.end()) {
                table.erase(low);
                low -= 1;
            }
            int high = n + 1;
            while (table.find(high) != table.end()) {
                table.erase(high);
                high += 1;
            }

            longest = ::max(longest, high - low - 1);
        }
        return longest;
    }
