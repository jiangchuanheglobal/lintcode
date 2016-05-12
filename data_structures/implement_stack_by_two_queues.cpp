class Stack {
public:
    // Push a new item into the stack
    void push(int x) {
        // Write your code here
        if (!que2.empty()) {
            que2.push(x);
        } else {
            que1.push(x);
        }
    }

    // Pop the top of the stack
    void pop() {
        // Write your code here
         if (!que1.empty()) {
            while (que1.size() > 1) {
                que2.push(que1.front());
                que1.pop();
            }
            que1.pop();
        } else {
            while (que2.size() > 1) {
                que1.push(que2.front());
                que2.pop();
            }
            que2.pop();
        }
    }

    // Return the top of the stack
    int top() {
        // Write your code here
        if (!que1.empty()) {
            while (que1.size() > 1) {
                que2.push(que1.front());
                que1.pop();
            }
            int last = que1.front();
            que1.pop();
            que2.push(last);
            return last;
        } else {
            while (que2.size() > 1) {
                que1.push(que2.front());
                que2.pop();
            }
            int last = que2.front();
            que2.pop();
            que1.push(last);
            return last;
        }
    }

    // Check the stack is empty or not.
    bool isEmpty() {
        // Write your code here
        return que1.empty() && que2.empty();
    }
    queue<int> que1;
    queue<int> que2;
};
