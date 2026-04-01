class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stack; //pair: temp, index
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            

            while (!stack.empty() && stack.top().first < temperatures[i]) {
                auto pair = stack.top();
                stack.pop();
                result[pair.second] = i - pair.second;

            }

            stack.push({temperatures[i], i});


        }

        return result;
        
    }
};
