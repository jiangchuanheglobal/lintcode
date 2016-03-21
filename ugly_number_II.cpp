class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        set<int> unique;
        priority_queue<long long, vector<long long>, std::greater<long long> > pq;
        vector<int> primes{2, 3, 5};
        
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
