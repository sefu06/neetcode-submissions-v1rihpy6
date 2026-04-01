class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_set<int> visited;

        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        if (!dfs(0, -1, adj, visited)) {
            return false;

        }

        if (visited.size() != n) {
            return false;

        }

        return true;

    }

bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visited) {
    visited.insert(node);
    for (int neighbour: adj[node]) {
        if (neighbour == parent) {
            continue;

        }

        if (visited.count(neighbour)) {
            return false;

        }

        if (!dfs(neighbour, node, adj, visited)) {
            return false;

        }

    }
    return true;

}
};
