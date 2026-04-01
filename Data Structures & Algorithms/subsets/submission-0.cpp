class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        backtrack(0, nums, current);
        return result;
        
    }

    void backtrack(int start, vector<int>& nums, vector<int>& current) {
          result.push_back(current);

        for (int i = start; i < nums.size(); i++) {
            // choose
            current.push_back(nums[i]);

            // explore
            backtrack(i + 1, nums, current);

            // un-choose (backtrack)
            current.pop_back();
        }

    }
};
