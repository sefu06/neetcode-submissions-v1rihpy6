class Solution {
public:
vector<string> result;
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtrack(0, 0, n, curr);
        return result;
        
    }

    void backtrack(int open, int close, int n, string curr){
        if (curr.length() == 2*n) {
            result.push_back(curr);
            return;

        }

        if (open < n) {
            curr+="(";
            backtrack(open+1, close, n, curr);
            curr.pop_back();

        }

        if (open > close) {
            curr+=")";
            backtrack(open, close+1, n, curr);
            curr.pop_back();

        }

            

    }

};
