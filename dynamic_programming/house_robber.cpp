class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
        if (A.size() < 2) {
            return A.size() == 0 ? 0 : A[0];
        }
        
        int size = A.size();
        long long f[2];
        f[0] = A[0];
        f[1] = A[0] > A[1] ? A[0] : A[1];
        
        for (int i = 2; i < size; i++) {
            f[i%2] = ::max(f[i - 2]%2, f[i - 1]%2 + A[i]);
            
        }
        
        return f[size - 1];
    }
};

//  fn-1, fn-2
