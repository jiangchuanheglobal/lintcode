class ResultType {
  public:
  ResultType(int left, int right, int biggest) {
      this->left = left;
      this->right = right;
      this->biggest = biggest;
  }
  int left;
  int right;
  int biggest;
};

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
        vector<int> presum(A.size() + 1, 0);
        presum[0] = 0;
        for (int i = 1; i <= A.size(); i++) {
            if (i == 1) {
                presum[i] = A[i - 1];
            } else {
                presum[i] = presum[i - 1] + A[i - 1];
            }
        }
        
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
        return ans;
    }
    
    
    
    
    vector<int> brute_force(vector<int>& A) {
        // O(N^2)
        vector<int> presum(A.size() + 1, 0);
        presum[0] = 0;
        for (int i = 1; i <= A.size(); i++) {
            if (i == 1) {
                presum[i] = A[i - 1];
            } else {
                presum[i] = presum[i - 1] + A[i - 1];
            }
        }
        
        vector<int> ans;
        int biggest = INT_MIN;
        for (int i = 0; i < A.size(); i++) { // [0, n - 1]
            for (int j = i + 1; j <= A.size(); j++) { // [1, n]
                if (biggest < presum[j] - presum[i]) {
                    biggest = presum[j] - presum[i];
                    ans.clear();
                    ans.push_back(i);
                    ans.push_back(j - 1);
                }
            }
        }
        return ans;
    }
    
    ResultType divide_and_conquer(vector<int>& A, int start, int end) {
        if (start > end) return ResultType(0, 0, INT_MIN);
        if (start == end) return ResultType(start, end, A[start]);
        
        int mid = start + (end - start) / 2;
        
        ResultType left_res = divide_and_conquer(A, start, mid);
        ResultType right_res = divide_and_conquer(A, mid + 1, end);
        
        int sum = 0;
        int left = 0;
        int left_biggest = INT_MIN;
        for (int i = mid; i >= 0; i--) {
            sum += A[i];
            if (sum > left_biggest) {
                left = i;
                left_biggest = sum;
            }
        }
        
        int right = 0;
        int right_biggest = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= end; i++) {
            sum += A[i];
            if (sum > right_biggest) {
                right = i;
                right_biggest = sum;
            }
        }
        
        int across_biggest = left_biggest + right_biggest;
        
        int biggest = ::max(left_res.biggest, ::max(right_res.biggest, across_biggest));
        if (biggest == left_res.biggest) {
            return left_res;
        } else if (biggest == right_res.biggest) {
            return right_res;
        } else {
            return ResultType(left, right, across_biggest);
        }
    }
};

