class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); 

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int front = i+1;
            int back = nums.size() - 1;
            int target = -nums[i];
            while (front < back) {
                vector<int> set;
              
                if (nums[front]+nums[back] == target) {
                    set.push_back(nums[front]);
                    set.push_back(-target);
                    set.push_back(nums[back]);

                    result.push_back(set);

                    front++;
                    back--;

                    while (front < back && nums[front] == nums[front - 1]) front++;
                    while (front < back && nums[back] == nums[back + 1]) back--;

                }
                else if (nums[front]+nums[back] < target){
                    front++;

                } else {
                    back--;
                }



            }

        }

        return result;

        
        

    }
};
