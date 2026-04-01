class Solution {
public:
vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(), false);
        dfs(nums, curr, used);
        return result;
        
    }

    void dfs(vector<int>& nums,  vector<int> curr, vector<bool> used) {
        if (curr.size() == nums.size()) {
            result.push_back(curr);
            return;

        }

        for (int i = 0; i < nums.size(); i++ ) {
            if (!used[i]) {
                curr.push_back(nums[i]);
                used[i] = true;
                dfs(nums, curr, used);
                curr.pop_back();
                used[i]=false;


            }
            
            

        }

    }
};
