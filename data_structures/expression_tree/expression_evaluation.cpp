class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        // write your code here
        if (expression.size() == 0) return 0;
        // convert to RPN
        vector<string> rpn = convertToRPN(expression);
        stack<string> num_stack;
        for (int i = 0; i < rpn.size(); i++) {
            string op = rpn[i];
            if (!is_operator(op)) {
                num_stack.push(op);
            } else {
                string op2 = num_stack.top();
                num_stack.pop();
                string op1 = num_stack.top();
                num_stack.pop();
                
                num_stack.push(evaluate(op1, op2, op));
            }
        }
        return num_stack.empty() ? 0 : stoi(num_stack.top());
    }
    
    string evaluate(string& op1, string& op2, string op) {
        int num1 = stoi(op1);
        int num2 = stoi(op2);
        char c = op[0];
        switch (c) {
            case '*':
            return std::to_string(num1 * num2);
            case '/':
            return std::to_string(num1 / num2);
            case '+':
            return std::to_string(num1 + num2);
            case '-':
            return std::to_string(num1 - num2);
        }
        return "";
    }
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
