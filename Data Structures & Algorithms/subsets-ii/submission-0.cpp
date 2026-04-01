class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        backtrack(0, nums, curr);
        return result;
        
    }

    void backtrack(int start, vector<int>& nums, vector<int> curr){
        result.push_back(curr);


        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr);
            curr.pop_back();
        }

    }
};
