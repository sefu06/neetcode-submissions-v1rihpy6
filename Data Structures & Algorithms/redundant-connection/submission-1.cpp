class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        
        vector<int> result;



        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];

            vector<bool> visited(n + 1, false);


            if (dfs(u, v, adj, visited)) {
                result = {u, v};

            }

            adj[u].push_back(v);
            adj[v].push_back(u);


        }

        return result;

        
    }

    bool dfs(int u, int v, vector<vector<int>>& adj, vector<bool>& visited) {
        if (u == v) return true;

        visited[u] = true;

          for (int nei : adj[u]) {
            if (!visited[nei]) {
                if (dfs(nei, v, adj, visited)) {
                    return true;
                }
            }

    }

    return false;
    }
};
