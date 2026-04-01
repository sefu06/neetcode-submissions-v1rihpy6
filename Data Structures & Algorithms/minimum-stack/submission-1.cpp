class MinStack {
    std::stack<int> stack;
    std::stack<int> minStack;
    int min = INT_MAX;
    int secondMin = INT_MAX;
public:
    MinStack() {
        
    }
    
    void push(int val) {
         stack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    
    void pop() {
        int top = stack.top();
        stack.pop();

        if (top == minStack.top()) {
            minStack.pop();

        }
        
        
    }
    
    int top() {
        return stack.top();
        
    }
    
    int getMin() {
        return minStack.top();
        
    }
};
