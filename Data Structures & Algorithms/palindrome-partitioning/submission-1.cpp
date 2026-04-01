class Solution {
public:
vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        backtrack(s, 0, temp);
        return result;
        
    }

    void backtrack(string s, int start, vector<string> temp) {
        if (start == s.length()) {
            result.push_back(temp);
            return;
        }

        for (int i = start; i < s.length(); i++) {
            if (isPalindrone(s, start, i)) {
                temp.push_back(s.substr(start, i - start + 1));
                backtrack(s, i+1, temp);
                temp.pop_back();

            }

        }


    }

    bool isPalindrone(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;

        }

        return true;

    }
};
