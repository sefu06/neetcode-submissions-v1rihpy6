class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right -left)/2;
            
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid+1;
                }

            } else {
                if (nums[mid] <= target && target <= nums[right] ) {
                    left = mid;
                } else {
                    right = mid-1;
                }
                
            }

        }

        if (nums[left] != target) {
            return -1;
        
        } else {
            return left;
        }
        
    }
};
