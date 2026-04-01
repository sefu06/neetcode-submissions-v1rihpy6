class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix.size()-1;
        int m = 0;

        while (left <= right) {
            m = left + (right - left)/2;
            if (matrix[m][0] > target) {
                right = m-1;

            } else if (matrix[m].back() < target) {
                left = m + 1;
            } else {
                break;
            }


        }



        int rowleft = 0;
        int rowright = matrix[m].size()-1;

        while (rowleft <= rowright) {
            int m2 = rowleft + (rowright - rowleft)/2;
            if (matrix[m][m2] > target) {
                rowright = m2-1;

            } else if (matrix[m][m2] < target) {
                rowleft = m2 + 1;
            } else {
                return true;
            }



        }

        return false;

        
    }
};
