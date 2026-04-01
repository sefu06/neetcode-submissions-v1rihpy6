class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        backtrack(0, nums, current, target);
        return result;
        
    }


      void backtrack(int start, vector<int>& nums, vector<int>& current, int target) {
         if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0) {
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i, nums, current, target - nums[i]); // reuse allowed
            current.pop_back();
        }
      }
};
