class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {{')', '('},
                                                      {']', '['},
                                                      {'}', '{'}};

    for (int i = 0; i < s.length(); i++) {
        if (closeToOpen.count(s[i])) {
            if (!stack.empty() && stack.top() == closeToOpen[s[i]]) {
                stack.pop();

            }else {
                return false;
            }

        
        

        } else {
            
        stack.push(s[i]);
    }
    }

    return stack.empty();


    }

    

    
};
