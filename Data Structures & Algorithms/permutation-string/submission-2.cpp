class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        /*
        create a freq array for s1, initialize another one that we will use for s2

        using sliding window approach, so left starts at 0 and right starts at s1.length()-1
        we update the frequencies as we go along, if it equals freq array for s1, we return true;
        */
        if (s1.size() > s2.size()) return false;


        vector<int> s1array(26, 0);
        vector<int> s2array(26, 0);



        for (int i = 0; i < s1.length(); i++) {
            s1array[s1[i]-'a']++;
            s2array[s2[i]-'a']++;

        }

        int left = 0;
        int right = s1.length() - 1; 

        while (right <= s2.length() - 1) {
            if (s1array == s2array) {
                return true;
            }

            s2array[s2[left] - 'a']--;
            left++;
            right++;
            s2array[s2[right] - 'a']++;

        }

        return false;
        
    }
};
