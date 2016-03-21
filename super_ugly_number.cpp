class Solution {
public:
    /**
     * @param n a positive integer
     * @param primes the given prime list
     * @return the nth super ugly number
     */
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // Write your code here
        set<long long> unique;
        priority_queue<long long, vector<long long>, std::greater<long long> > pq;
        
        for (auto& p : primes) {
            pq.push(p);
            unique.insert(p);
        }
       
        long long num = 1;
        for (int i = 0; i < n - 1; i++) {
            num = pq.top();
            pq.pop();
            unique.erase(num);
            for (auto& p : primes) {
                long long next = num * p;
                if (unique.find(next) == unique.end()) {
                    pq.push(next);
                    unique.insert(next);
                }
            }
        }
        
        return num;
    }
};
