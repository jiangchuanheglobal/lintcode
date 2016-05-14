/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        // write your code here
        int num = nuts.size();
        helper(nuts, bolts, 0, num - 1, compare);
    }
    
    void helper(vector<string> &nuts, vector<string> &bolts, int start, int end, Comparator& compare) {
        if (start >= end) return;
        
        string bolt = bolts[start];
        int index = partition(nuts, start, end, bolt, compare);
        string matching_nut = nuts[index];
        
        partition(bolts, start, end, matching_nut, compare);
        
        helper(nuts, bolts, start, index - 1, compare);
        helper(nuts, bolts, index + 1, end, compare);
    }
    
    int partition(vector<string>& arr, int left, int right, string pivot, Comparator& compare) {
        for (int i = left; i < right; ) {
            if (compare.cmp(arr[i], pivot) == -1 ||  // Smaller.
                (compare.cmp(arr[i], pivot) == 2 &&
                 compare.cmp(pivot, arr[i]) == 1)) {
                swap(arr[left++], arr[i++]);
            } else if (compare.cmp(arr[i], pivot) == 1 ||  // Bigger.
                      (compare.cmp(arr[i], pivot) == 2 &&
                       compare.cmp(pivot, arr[i]) == -1)) {
                ++i;
            } else {  // Equal.
                swap(arr[i], arr[right]);
            }
        }
        // Put the pivot to the partition index.
        swap(arr[left], arr[right]);

        // Return the partition index of an array.
        return left;

    }
    
    void swap(string& i, string& j) {
        string tmp = i;
        i = j;
        j = tmp;
    }
    
};
