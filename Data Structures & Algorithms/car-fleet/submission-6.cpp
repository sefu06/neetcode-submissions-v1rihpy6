class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int result = 1;
        stack<double> stack;

        //sort by descending
        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});

        }

        sort(cars.rbegin(), cars.rend());


        for (int i = 0; i < position.size(); i++) {

            while (stack.empty() || cars[i].second > stack.top()) {
                stack.push(cars[i].second);

            }

            
            
            

        }

        return stack.size();
        
    }
};
