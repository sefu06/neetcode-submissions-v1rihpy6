class Solution {
    /*
    we want shortest path on a directed graph so we should dijkstras.

    make an adjacency list with each edge being pair<neighbour, edge weight>
    make an visited node list.

    while (visited.size() != n) 

    then remove k from unvisited node list add its neighbours to 
    unvisited nodes to a min-heap.

    then take the top of the min heap mark as visited and add its nuvistied neigbours
    
    if (minheap is empty) return -1;

    */
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;


        for (auto edge : times) {
            int node = edge[0];
            int neighbour = edge[1];
            int weight = edge[2];

            adj[node].push_back({weight, neighbour});
        }
        

        minHeap.push({0, k});
        
        while (!minHeap.empty()) {
            auto [time, node] = minHeap.top();
            minHeap.pop();
            for (auto [weight, neighbor] : adj[node]) {
                int newTime = time + weight;
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    minHeap.push({newTime, neighbor});
                }
            }

        }

        int result = 0;

        for (int i = 1; i <= n; i++ ) {
            if (dist[i]== INT_MAX) {
                return -1;

            }

            result = max(result, dist[i]);

        }

        return result;

    }
};
