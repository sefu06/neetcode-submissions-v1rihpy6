class Solution {
    /*
    iterate through the string with index i as the center of the palindrone.
    Then, we need to consider two cases: odd length and even length.

    for odd if (string[i+1] == string[i-1]) continue 

    for even if (string[i] == string[i+1]) continue
    */
public:
    string longestPalindrome(string s) {
        int resLen = 0;
        string res = ""; // starting index of longest palindrone

        if (s.length() < 2) return s;

        for (int i = 0; i < s.size(); i++) {
            for (int j=i; j< s.size(); j++) {
                int l = i, r = j;
                 while (l < r && s[l] == s[r]) {
                    l++;
                    r--;
                }

                if (l >= r && resLen < (j - i + 1)) {
                    res = s.substr(i, j - i + 1);
                    resLen = j - i + 1;
                }

            }


        }

        return res;

        
    }
};
