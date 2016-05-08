class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int start, end;
        start = 1;
        end = INT_MIN;
        for (int i = 0; i < L.size(); i++) {
            end = ::max(end, L[i]);
        }
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            int sum = counts(L, mid);
            
            if (sum < k) {
                end = mid;
            } else if (sum > k) {
                start = mid;
            } else {// equal
                start = mid;
            }
        }
        
        if (counts(L, end) >= k) return end;
        else if (counts(L, start) >= k) return start;
        return 0;
    }
    
    int counts(vector<int>& L, int len) {
        int sum = 0;
        for (int i = 0; i < L.size(); i++) {
            sum += L[i] / len;
        }
        return sum;
    }
    
};
