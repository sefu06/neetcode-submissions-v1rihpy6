class Solution {
    /*
    use dfs to detect for cycles. Start at node 0, and then recursively visit
    its children. if we encounter and node that we alr viited than that is a cycle.

    make a hashset of visited to check for cycles. after dfs is performed, 
    cycle through visited to make sure that we have all the nodes in the tree.
    */
public:


bool validTree(int n, vector<vector<int>>& edges) {
    unordered_set<int> visited;
        vector<vector<int>> adj(n);
     

for (auto& e : edges) {
    int u = e[0];
    int v = e[1];
    adj[u].push_back(v);
    adj[v].push_back(u);
}
        
        if (!dfs(0, -1, adj, visited)) {
            return false;

        }
        
        if (visited.size() == n) {
            return true;

        }

        return false;

    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(node);
        
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;

        if (visited.count(neighbor)) {
            return false;
        }

        if (!dfs(neighbor, node,  adj, visited)) {
            return false; 
        }

    }

    return true;
    }
};


