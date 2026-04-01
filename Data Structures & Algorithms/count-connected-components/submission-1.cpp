class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        vector<vector<int>> adj(n);
        int result = 0;

        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                result++;

            }

            dfs(i, adj, visited);

        }

        return result;

    }

    void dfs(int node, vector<vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(node);

        for (int neighbour : adj[node]) {
            if (visited.count(neighbour)) {
                continue;
            }

            dfs(neighbour, adj, visited);

        }

    }
};
