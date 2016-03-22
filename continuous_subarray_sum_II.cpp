class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        
        int sum = 0;
        for (auto& a : A) {
            sum += a;
        }
        vector<int> presum(A.size() + 1, 0);
        presum[0] = 0;
        for (int i = 1; i <= A.size(); i++) {
            if (i == 1) {
                presum[i] = A[i - 1];
            } else {
                presum[i] = presum[i - 1] + A[i - 1];
            }
        }
        
        // get largest subarray
        vector<int> ans;
        int smallest_index = 0;
        int biggest = INT_MIN;
        for (int i = 1; i < presum.size(); i++) {
            if (presum[i] - presum[smallest_index] > biggest) {
                biggest = presum[i] - presum[smallest_index];
                ans.clear();
                ans.push_back(smallest_index);
                ans.push_back(i - 1);
            }
            if (presum[smallest_index] > presum[i]) {
                smallest_index = i;
            }
        }
        
        
        // get smallest subarray
        vector<int> ans2;
        int largest_index = 0;
        int smallest = INT_MAX;
        for (int i = 1; i < presum.size(); i++) {
            if (presum[i] - presum[largest_index] < smallest) {
                smallest = presum[i] - presum[largest_index];
                ans2 = computeRange(largest_index, i - 1, A.size());
            }
            if (presum[largest_index] < presum[i]) {
                largest_index = i;
            }
        }
        
        if (sum == smallest) { // needs better explain
            return ans;
        } else {
            return sum - smallest > biggest ? ans2 : ans;
        }
    }
    
    vector<int> computeRange(int i, int j, int size) {
        if (i - 1 >= 0 && j + 1 < size) {
            vector<int> ans = {j + 1, i - 1};
            return ans;
        } else if (i - 1 < 0) {
            vector<int> ans = {j + 1, size - 1};
            return ans;
        } else {
            vector<int> ans = {0, i - 1};
            return ans;
        }
    }
    
};
