class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int frontIndex = 0;
        int backIndex = numbers.size() - 1;
        vector<int> result;

        while (frontIndex < backIndex) {
            if (numbers[frontIndex]+numbers[backIndex] > target) {
                backIndex--;

            } else if (numbers[frontIndex]+ numbers[backIndex] < target) {
                frontIndex++;

            } else if (numbers[frontIndex] + numbers[backIndex] == target) {
                result.push_back(frontIndex + 1);
                result.push_back(backIndex + 1);
                return result;

            }

        }

       

        return result;
        
    }
};
