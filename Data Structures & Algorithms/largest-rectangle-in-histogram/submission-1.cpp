class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> stack;
        vector<int> index;
        int right = 0;
        int left = 0;
        int result = 0;
        int width = 0;



        for (int i = 0; i < heights.size(); i++) {
            while (!stack.empty() && heights[i] < heights[stack.top()]) {
                left = stack.top();
                stack.pop();
                if (stack.empty()) {
                 width = i;
                } else {
                 width = i - stack.top() - 1;
                }
                result = max(result, heights[left] * width);

            }
            stack.push(i);

        }


        while (!stack.empty()) {
            int h = heights[stack.top()];
            stack.pop();
            if (stack.empty()) {
                 width = heights.size();
                } else {
                 width = heights.size() - stack.top() - 1;
                }
            result = max(result, h * width);

        }

        return result;

        
        
        
    }


};
