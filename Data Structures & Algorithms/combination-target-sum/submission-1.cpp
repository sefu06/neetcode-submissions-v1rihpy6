class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        backtrack(nums, res, comb, target, 0);
        return res;

        
    }

private:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& comb, int target, int start) {

        if (target==0) {
            res.push_back(comb);
            return;

        }

        if (target < 0) {
            return;

        }

        for (int i = start; i <  nums.size(); i++) {
            comb.push_back(nums[i]);
            backtrack(nums, res, comb, target - nums[i], i);
            comb.pop_back();
        }

    }
};
