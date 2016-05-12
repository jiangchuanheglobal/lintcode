class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if (!minStk.empty()) {
            if (number <= minStk.top()) {
                minStk.push(number);
            }
        } else {
            minStk.push(number);
        }
        stk.push(number);
    }

    int pop() {
        // write your code here
        if (stk.empty()) return INT_MIN;
        if (stk.top() == minStk.top()) {
            minStk.pop();
        }
        
        int number = stk.top();
        stk.pop();
        return number;
    }

    int min() {
        // write your code here
        return minStk.top();
    }
    
    stack<int> stk;
    stack<int> minStk;
};
