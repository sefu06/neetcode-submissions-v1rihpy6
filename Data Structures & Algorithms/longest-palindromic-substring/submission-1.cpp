class Solution {
    /*
    iterate through the string with index i as the center of the palindrone.
    Then, we need to consider two cases: odd length and even length.

    for odd if (string[i+1] == string[i-1]) continue 

    for even if (string[i] == string[i+1]) continue
    */
public:
    string longestPalindrome(string s) {
        int resIdx = 0, resLen = 0;
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] &&
                    (j - i <= 2 || dp[i + 1][j - 1])) {

                    dp[i][j] = true;
                    if (resLen < (j - i + 1)) {
                        resIdx = i;
                        resLen = j - i + 1;
                    }
                }
            }
        }

        return s.substr(resIdx, resLen);
            
        
    }
};
