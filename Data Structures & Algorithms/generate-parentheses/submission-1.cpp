class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> result; 
        string curr;
        dfs(0, 0, n, result, curr);
        return result;
    }

    void dfs(int open, int close, int n, vector<string>& result, string& curr) {
        if (open + close == 2*n) {
            result.push_back(curr);

        }

        if (open < n) {
            curr += "(";
            dfs(open + 1, close, n, result, curr);
            curr.pop_back();

        }

        if (close < open) {
            curr += ")";
            dfs(open, close +1, n, result, curr);
            curr.pop_back();

        }

        


        

    }
};
