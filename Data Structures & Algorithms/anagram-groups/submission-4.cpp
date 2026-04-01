class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (int j = 0; j < strs[i].length(); j++) {
                count[strs[i][j] - 'a']++;
            }

            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }

            res[key].push_back(strs[i]);

        }

        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }

        return result;
        
    }
};
