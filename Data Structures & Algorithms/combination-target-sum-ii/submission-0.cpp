class Solution {
    //to avoid duplicates, first take the input array and sort it
    //--> this is so that we can skip element if alr used

public:
vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> current;

        dfs(candidates, target, 0, current, 0);
        return result;
        
    }

    void dfs(vector<int>& candidates, int target, int i, vector<int>& current, int total) {
        if (total == target) {
            result.push_back(current);
            return;
            
        }
        if (total > target || i == candidates.size()) {
            return;

        }

        current.push_back(candidates[i]);
        dfs(candidates, target, i+1, current, total + candidates[i]);
        current.pop_back();

        while (i+1<candidates.size() && candidates[i] == candidates[i+1]) {
            i++;

        }
        dfs(candidates, target, i + 1, current, total);

    }


};
