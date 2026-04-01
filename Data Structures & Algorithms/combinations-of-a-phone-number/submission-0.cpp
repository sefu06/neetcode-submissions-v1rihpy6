class Solution {
public:
vector<string> result;
unordered_map<char, string> phone = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

    vector<string> letterCombinations(string digits) {
        string curr;
        backtrack(digits, curr,0);
        return result;
        
    }

    void backtrack(string digits, string curr, int index) {
        if (curr.length() == digits.length() && curr != "") {
            result.push_back(curr);

        }
        for (int i = 0; i < phone[digits[index]].length();i++) {
            curr.push_back(phone[digits[index]][i]);
            backtrack(digits, curr, index + 1);
            curr.pop_back();

        }

    }
};
