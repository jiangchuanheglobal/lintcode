

class Stack {
public:
    
    // Push a new item into the stack
    void push(int x) {
        // Write your code here
        stk.push_back(x);
    }

    // Pop the top of the stack
    void pop() {
        // Write your code here
        stk.pop_back();
    }

    // Return the top of the stack
    int top() {
        // Write your code here
        return stk.back();
    }

    // Check the stack is empty or not.
    bool isEmpty() {
        // Write your code here
        return stk.empty();
    }
    
   vector<int> stk;
};
