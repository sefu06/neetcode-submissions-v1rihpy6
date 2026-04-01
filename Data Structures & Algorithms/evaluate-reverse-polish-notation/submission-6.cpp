class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //int result = stoi(tokens[0]);
        stack<int> stack;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {

                if (tokens[i] == "+") {
                    int top = stack.top();
                    stack.pop();
                    int secondTop = stack.top();
                    stack.pop();
                    stack.push(top + secondTop);

                }

                if (tokens[i] == "-") {
                    int top = stack.top();
                    stack.pop();
                    int secondTop = stack.top();
                    stack.pop();
                    stack.push(secondTop -top);

                }


                if (tokens[i] == "*") {
                    int top = stack.top();
                    stack.pop();
                    int secondTop = stack.top();
                    stack.pop();
                    stack.push(top * secondTop);

                }


                if (tokens[i] == "/") {
                    int top = stack.top();
                    stack.pop();
                    int secondTop = stack.top();
                    stack.pop();
                    stack.push(secondTop/top);

                }

            } else {
                stack.push(stoi(tokens[i]));
            }

        }

        return stack.top();
        
    }
};
