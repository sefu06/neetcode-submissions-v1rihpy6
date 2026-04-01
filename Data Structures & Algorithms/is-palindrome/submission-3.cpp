class Solution {
public:
    bool isPalindrome(string s) {
        int currentFront = 0;
        int currentBack = s.length() - 1;
        
        while (currentFront <= currentBack) {
            

            if (!isalnum(s[currentFront])) {
                currentFront++;
            }
            
            if (!isalnum(s[currentBack])) {
                currentBack--;
            }

            if (isalnum(s[currentFront]) && isalnum(s[currentBack])) {
                if (tolower(s[currentFront]) != tolower(s[currentBack])) {
                    return false;

                }
                currentFront++;
                currentBack--;

            }

        }

        return true;

        
        
    }
};
