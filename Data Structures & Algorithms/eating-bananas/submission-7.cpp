class Solution {
    /*
    this is binary search so we should sort first?
    upper bound for k is largest number in piles
    */
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int result = 0;
        sort(piles.begin(), piles.end());
        int l = 1;
        int r = piles[piles.size()-1];

        result = r;

        while (l <= r) {
            
            int m = l + ((r-l)/2);
            //calculate how many hours it would take with k = m
            int hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                hours += (piles[i] + m - 1) / m;

            }

            if (hours > h) {
                l = m+1;
                

            } else if (hours <= h) {
                result = m;
                r = m-1;
               

            }
        }

        return result;
 
    }
};
