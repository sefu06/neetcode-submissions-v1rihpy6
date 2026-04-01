class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1count(26, 0);
        vector<int> s2count(26, 0);
        int front = 0;
        int matches = 0;

        if (s1.length() > s2.length()) {
            return false;

        }

        for (int i = 0; i < s1.length(); i++) {
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;

        }

         for (int i = 0; i < 26; i++) {
            if (s1count[i] == s2count[i]) {
                matches++;
            }
        }

       

        for (int back = s1.length(); back < s2.length(); back++) {

            if (matches == 26) {
                return true;

            }

            s2count[s2[back]-'a']++;
            if (s2count[s2[back]-'a'] == s1count[s2[back]-'a']) {
                matches++;

            }

            if (s2count[s2[back]-'a'] - 1 == s1count[s2[back]-'a']) {
                matches--;

            }

            //s2count[s2[back]-'a']++;

            
            s2count[s2[front]-'a']--;

            if (s2count[s2[front]-'a'] == s1count[s2[front]-'a']) {
                matches++;

            }

            if (s2count[s2[front]-'a'] + 1 == s1count[s2[front]-'a']) {
                matches--;

            }
            front++;
            


        }

        return matches == 26;
        
    }
};
