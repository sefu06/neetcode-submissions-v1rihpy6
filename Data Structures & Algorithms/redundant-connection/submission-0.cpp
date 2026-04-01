class Solution {
public:
    vector<int> result;

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            vector<bool> visited(n + 1, false);

            // if u and v already connected → cycle
            if (dfs(u, v, adj, visited)) {
                result = {u, v};   // overwrite to keep LAST one
            }

            // add edge after check
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return result;
    }

    bool dfs(int curr, int target,
             vector<vector<int>>& adj,
             vector<bool>& visited) {

        if (curr == target) return true;
        visited[curr] = true;

        for (int nei : adj[curr]) {
            if (!visited[nei]) {
                if (dfs(nei, target, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
