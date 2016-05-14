class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        if (A.size() < 2) return;
        
        int cnt = positiveCount(A);
        
        std::sort(A.begin(), A.end());
        
        int start;
        int end;
        if (A.size() % 2 == 0) {
            start = 0;
            end = A.size() - 1;
        } else {
            if (cnt * 2 > A.size()) {
                start = 0;
                end = A.size() - 2;
            } else {
                start = 1;
                end = A.size() - 1;
            }
        }
        
        while (start < end) {
            swap(A[start], A[end]);
            start += 2;
            end -= 2;
        }
    }

    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
    int positiveCount(vector<int>& A) {
        int cnt = 0;
        for (auto& a : A) {
            if (a > 0) {
                cnt += 1;
            }
        }
        return cnt;
    }
};
