class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int x = 0;
        for (auto& a : A) {
            x ^= a;
        }
        
        int flag = x - (x&(x - 1)); // get the bit that n1 has, n2 does not
        
        int n1 = 0;
        int n2 = 0;
        for (auto& a : A) {
            if (flag & a) {
                n1 ^= a;
            } else {
                n2 ^= a;
            }
        }
        vector<int> ans{n1, n2};
        return ans;
    }
};
