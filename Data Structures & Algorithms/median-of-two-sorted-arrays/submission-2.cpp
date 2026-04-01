class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);

        }
        int total = nums1.size() + nums2.size();
        int half = (total + 1) / 2;
        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            int i = left + (right - left) / 2;  // how many from nums1 in the left half
            int j = half - i;                  // how many from nums2 in the left half

            // edges
            int Aleft  = (i == 0 ? INT_MIN : nums1[i - 1]);
            int Aright = (i == m ? INT_MAX : nums1[i]);
            int Bleft  = (j == 0 ? INT_MIN : nums2[j - 1]);
            int Bright = (j == n ? INT_MAX : nums2[j]);
            if (Aleft <= Bright && Bleft <= Aright) {

                 if (total % 2 == 1) {
                    return max(Aleft, Bleft);
                }
                // even
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;

            } else if (Aleft > Bright) {
                right = i - 1;
            }

            else {
                left = i + 1;
            }
        }

        return 0.0; 
        
    }
};
