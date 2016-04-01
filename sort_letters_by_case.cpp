class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        // write your code here
        partitionLetters(letters, 'Z');
    }
     int partitionLetters(string &letters, char k) {
        // write your code here
        
        int i = 0;
        int j = letters.length() - 1;
        while (i <= j) {
            if (letters[j] > k) {
                swap(letters, i, j);
                i += 1;
            } else {
                j -= 1;
            }
        }
        return i;
    }
    
    void swap(string& nums, int i, int j) {
        char tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
