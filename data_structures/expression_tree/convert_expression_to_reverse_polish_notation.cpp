class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        // write your code here
        
        stack<string> op_stack;
        vector<string> result;
        
        for (int i = 0; i < expression.size(); i++) {
            string op = expression[i];
            if (is_operator(op)) {
                while (!op_stack.empty() && !isHigherPrecedence(op, op_stack.top())) {
                    result.push_back(op_stack.top());
                    op_stack.pop();
                }
                op_stack.push(op);
            } else if (op.compare("(") == 0) {
                op_stack.push(op);
            } else if (expression[i].compare(")") == 0) {
                while (!op_stack.empty() && op_stack.top().compare("(")) {
                    result.push_back(op_stack.top());
                    op_stack.pop();
                }
                op_stack.pop();
            } else { /* operand */
                result.push_back(op);
            } 
        }
        
        while (!op_stack.empty()) {
            result.push_back(op_stack.top());
            op_stack.pop();
        }
        
        return result;
    }
    
    // * /
    // + -
    
    bool is_operator(string& op) {
        return op.compare("*") == 0
        || op.compare("/") == 0
        || op.compare("+") == 0
        || op.compare("-") == 0;
    }
    bool isHigherPrecedence(string& op1, string& op2) {
        int op1_w = weightOfOperator(op1);
        int op2_w = weightOfOperator(op2);
        return op1_w < op2_w;
    }
    
    int weightOfOperator(string& op) {
        char c = op[0];
        switch (c) {
            case '*':
            case '/':
                return 0;
            case '+':
            case '-':
                return 1;
        } 
    }
};
