class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        // Write your code here
        int len = A.size();
        map<int, int> rep;
        long long fact = 1;
        long long multifact = 1;
        long long index = 0;
        
        for (int i = len - 1; i >= 0; i--) {
            if (rep.find(A[i]) == rep.end()) {
                rep[A[i]] = 1;
            } else {
                rep[A[i]] += 1;
                multifact *= rep[A[i]];
            }
            
            int count = 0;
            for (int j = i + 1; j < len; j++) {
                if (A[j] < A[i]) {
                    count += 1;
                }
            }
            
            index = index + count * fact / multifact;
            fact = fact * (len - i);
        }
        
        
        return index + 1;
    }
};
