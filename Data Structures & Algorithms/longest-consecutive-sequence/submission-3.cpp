class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        if (nums.empty()) return 0;


    
    
        
        for (int i = 0; i < nums.size(); i++) {

            if (numSet.find(nums[i] -1) == numSet.end()) {
                 int currentStreak = 1;
                int currentNum = nums[i];

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentStreak++;

                }

                  if (currentStreak > longest) {
                    longest = currentStreak;

            }

            }



            
        }

        return longest;
        
    }
};
