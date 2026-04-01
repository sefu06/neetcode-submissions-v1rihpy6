class Solution {
    /*

    this solution is similair to house robber 1, to solve the problem of houses 
    being circular, we initialize two arrays. first array contains first house to 
    second last house, second array contains second house to last house. Run both
    vectors recuresivley and then return the maximum result of the two.
    */

public:
vector<int> memo;

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> arr1(nums.begin(), nums.end() - 1);
        vector<int> arr2(nums.begin() + 1, nums.end());

        memo.assign(arr1.size(), -1);
        int ans1 = dfs(arr1, 0);

        memo.assign(arr2.size(), -1);
        int ans2 = dfs(arr2, 0);

        return max(ans1, ans2);   
        
    }

    int dfs(vector<int>& nums, int start) {
        if (start >= nums.size()) {
            return 0;

        }

        if (memo[start] != -1) {
            return memo[start];

        }

            memo[start] = max(
            dfs(nums, start + 1),
            nums[start] + dfs(nums, start + 2)
        );

        return memo[start];

    }
};
