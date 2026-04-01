class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1;
        vector<int> result;
        int zeroCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zeroCount++;


            } else {
                total = total * nums[i];
                }
            

        }

        if (zeroCount >= 2) {
           for (int i = 0; i < nums.size(); i++) {
        
            result.push_back(0);

        } 

        } else if (zeroCount == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    result.push_back(total);

                } else {
                    result.push_back(0);
                }
        
            

        }


        } else {

        for (int i = 0; i < nums.size(); i++) {
        
            result.push_back(total / nums[i]);

        }

        }

        

        return result;

    }
};
