class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        return canCompleteCircuit_linear(gas, cost);
    }
     /**
     * gas(i) - cost(i) + sum(gas(x) - cost(x)) < 0  // x in [i + 1, n]
     *
     * because gas(i) -cost(i) >= 0
     * then sum(gas(x) - cost(x)) < 0
     */
    int canCompleteCircuit_linear(vector<int> &gas, vector<int> &cost) {
      // write your code here
      int start = 0;
      bool find = false;
      int len = gas.size();
      while (start < len && !find) {
        int nextStart = start;
        if (canCompleteHelper2(start, gas, cost, nextStart)) {
            find = true;
        } else {
          start = nextStart;
        }
      }
      if (find) {
        return start;
      } else {
        return -1;
      }

    }

    bool canCompleteHelper2(int start, vector<int>& gas, vector<int>& cost, int& nextStart) {
      int i = 0;
      int left = 0;
      int len = gas.size();
      while (left + gas[(start + i) % len] >= cost[(start + i) % len] && i <= len) {
        left = left + gas[(start + i) % len] - cost[(start + i) % len];
        i += 1;
      }
      if (i > len) {
        return true;
      } else {
        nextStart = start + i + 1;
        return false;
      }
    }

    
     int canCompleteCircuit_naive(vector<int> &gas, vector<int> &cost) {
        // write your code here
      int start = 0;
      bool find = false;
      int len = gas.size();
      while (start < len && !find) {
        if (canCompleteHelper(start, gas, cost)) {
            find = true;
        } else {
            start += 1;
        }
      }
      if (find) {
        return start;
      } else {
        return -1;
      }
    }

    bool canCompleteHelper(int start, vector<int>& gas, vector<int>& cost) {
      int i = 0;
      int left = 0;
      int len = gas.size();
      while (left + gas[(start + i) % len] >= cost[(start + i) % len] && i <= len) {
        left = left + gas[(start + i) % len] - cost[(start + i) % len];
        i += 1;
      }
      if (i > len) {
        return true;
      } else {
        return false;
      }
    }

};
