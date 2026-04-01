class Solution {
public:
    int maxArea(vector<int>& heights) {
        int currentFrontIndex =0;
        int currentBackIndex =heights.size()-1;
        int maxFrontIndex = 0;
        int maxBackIndex = heights.size()-1;
        int result = min(heights[currentFrontIndex], heights[currentBackIndex]) * (currentBackIndex - currentFrontIndex);

        

        while (currentFrontIndex < currentBackIndex) {
            if (heights[currentFrontIndex] > heights[currentBackIndex]) {
                currentBackIndex--;

            } else {
                currentFrontIndex++;
            }

            
            if (min(heights[currentFrontIndex], heights[currentBackIndex]) * (currentBackIndex - currentFrontIndex) > result) {
                result = min(heights[currentFrontIndex], heights[currentBackIndex]) * (currentBackIndex - currentFrontIndex);
                
            }

           



        }

        return result;
    }
};
