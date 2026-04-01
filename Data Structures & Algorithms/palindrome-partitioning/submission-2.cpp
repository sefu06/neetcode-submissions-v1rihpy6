class Solution {
public:
vector<vector<string>> result;
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(s, curr, 0, 0);
        return result;

        
    }

private: 
bool isPali(string &s, int l, int r){
    while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;

}
void dfs(string s, vector<string>& curr, int i, int j) {
    if(i >= s.size()) {
        if (i == j) {
            result.push_back(curr);

        }
       return; 
    }

    if (isPali(s, j, i)) {
        curr.push_back(s.substr(j, i-j+1));
        dfs(s, curr, i+1, i+1);
        curr.pop_back();

    }

    dfs(s, curr, i+1, j);
    
}
};
