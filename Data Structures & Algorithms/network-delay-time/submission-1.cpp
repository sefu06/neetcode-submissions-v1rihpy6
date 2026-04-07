class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        unordered_set<int> visited;


        for (auto edge : times) {
            int node = edge[0];
            int neighbour = edge[1];
            int weight = edge[2];

            adj[node].push_back({weight, neighbour});
        }
        

        minHeap.push({0, k});

        while (!minHeap.empty()) {
            auto front = minHeap.top();
            minHeap.pop();

            if (visited.count(front.second)) {
                continue;
            }

            visited.insert(front.second);

            dist[front.second] = front.first;
            

            for (auto node : adj[front.second]) {
                minHeap.push({node.first+ front.first, node.second});

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
