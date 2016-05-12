class Solution {
public:
    /**
     * @param stk an integer stack
     * @return void
     */
    void stackSorting(stack<int>& stk1) {
        // Write your code here
        stack<int> stk2;
        while (!stk1.empty()) {
            int next = stk1.top();
            stk1.pop();
            while (!stk2.empty() && next > stk2.top()) {
                stk1.push(stk2.top());
                stk2.pop();
            }
            stk2.push(next);
        }
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
};
