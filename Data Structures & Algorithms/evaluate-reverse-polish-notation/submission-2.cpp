class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;
        int result = stoi(tokens[0]);

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                if (tokens[i] == "+") {
                    int top = numbers.top();
                    numbers.pop();
                    result = top + numbers.top();
                    numbers.pop();
                    numbers.push(result);
                }

                if (tokens[i] == "-") {
                    int top = numbers.top();
                    numbers.pop();
                    result = numbers.top() - top;
                    numbers.pop();
                    numbers.push(result);
                }

                  if (tokens[i] == "*") {
                    int top = numbers.top();
                    numbers.pop();
                    result = numbers.top() * top;
                    numbers.pop();
                    numbers.push(result);
                }

                if (tokens[i] == "/") {
                    int top = numbers.top();
                    numbers.pop();
                    result = numbers.top() / top;
                    numbers.pop();
                    numbers.push(result);
                }


            } else {
                numbers.push(stoi(tokens[i]));
            }



        }

        return numbers.top();
        
    }
};
