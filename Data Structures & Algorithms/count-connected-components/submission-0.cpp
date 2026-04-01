class Solution {
    /*
    make adjacency list, then perform dfs by looping nodes 0 to n-1. 
    when performing dfs add nodes to visited list. add neighbours until none left.
    add 1 to result everytime we start dfs on an unvisted node.
    */
public:
int result = 0;
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_set<int> visited;
        vector<vector<int>> adj(n);
     

for (auto e : edges) {
    int u = e[0];
    int v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
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
         for (int neighbor : adj[node]) {
            if (visited.count(neighbor)) {
                continue;
            }
            dfs(neighbor, adj, visited);
            
            
         }

    }


};
