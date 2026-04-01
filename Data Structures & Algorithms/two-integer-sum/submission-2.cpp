class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // use hashmap, then for each number in nums, search if target - nums[i] exists
        unordered_map<int, int> hash_map;
        vector<int> result;


        for (int i = 0; i < nums.size(); i++) {
            hash_map.insert({nums[i], i});

            if (hash_map.count(target-nums[i]) & i != hash_map[target - nums[i]]) {
                
                result.push_back(hash_map[target-nums[i]]);
                result.push_back(i);
                break;

            }

        }



        return result;
        
    }
};
