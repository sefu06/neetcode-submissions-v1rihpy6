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
        dfs(digits, curr, 0);
        return result;
        
    }

void dfs(string digits, string& curr, int index) {
    if (digits.size() == 0){
        return;

    }
    if (index >= digits.size()) {
        result.push_back(curr);

    }

    for (int i = 0; i < phone[digits[index]].size(); i++) {
        curr += phone[digits[index]][i];
        dfs(digits, curr, index+1);
        curr.pop_back();

    }

    

}
    
};
