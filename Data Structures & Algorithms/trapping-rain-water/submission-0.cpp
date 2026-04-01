class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());

        for (int i = 0; i < height.size(); i++) {
            if (i == 0) {
                maxLeft[i] = 0 ;
            } else {
                maxLeft[i] = max(maxLeft[i-1], height[i-1]);
            }
        }

        for (int i = height.size() -1; i >= 0; i--) {
            if (i == height.size() - 1) {
                maxRight[i] = 0;
            } else {

            maxRight[i] = max(maxRight[i + 1], height[i + 1]);
            }
        }

        for (int i = 0; i < height.size(); i++) {
            
            if(min(maxLeft[i], maxRight[i])-height[i]> 0) {
                result += min(maxLeft[i], maxRight[i])-height[i];

            }

        }

        return result;



        

        
        
    }
};
