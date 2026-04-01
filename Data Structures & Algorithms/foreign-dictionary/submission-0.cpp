class Solution {
public:
/*
toppological sort, so do a post-order dfs and then reverse for final result
keep track of visited and path. if we reach a node alr in path then that
is a cycle and return empty string
*/

    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, bool> visited, inPath;
    string result;

    bool dfs(char c) {
        if (inPath[c]) {
            return false;

        }

        if (visited[c]) {
            return true;
        }

        inPath[c] = true;

        for (auto nei : adj[c]) {
            if (!dfs(nei)) return false;
        }

        inPath[c] = false;

        visited[c] = true;
        result.push_back(c);
        return true;

    }

    string foreignDictionary(vector<string>& words) {
        for (auto word : words) {
            for (char ch : word) {
                adj[ch];
                visited[ch] = false;
                inPath[ch] = false;
            }

        }

        for (int i = 0; i < words.size()-1; i++) {
            auto w1 = words[i];
            auto w2 = words[i+1];

            int length = min(w1.size(), w2.size());
            bool foundDiff = false;

            for (int j = 0; j < length; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    foundDiff = true;
                    break;

                }

            }

            if (!foundDiff && w1.size() > w2.size())
            return "";

        }

          for (auto &[c, _] : adj) {
            if (!visited[c]) {
                if (!dfs(c)) return "";
            }
        }

        reverse(result.begin(), result.end());
        return result;

        
    }
};
