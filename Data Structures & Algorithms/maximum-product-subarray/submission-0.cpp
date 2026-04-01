class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        int prefix = 0;
        int suffix = 0;

        for (int i = 0; i < n; i++) {
            prefix = nums[i]*(prefix == 0 ? 1 : prefix);
            suffix= nums[n-1-i]*(suffix == 0 ? 1 : suffix);

            res = max(res, max(prefix, suffix));

        }

        return res;
        
    }
};
