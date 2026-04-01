class Solution {
    /*
    this is a mst problem. Lets use prims algo to find the mst.


    initialize:
    create an adjacency list unordered_map<node, pair<weight, node>
    create a visited list, we can stop when the lenght == points.size()
    create a minheap

    add first node and then in a while loop:
    pop the node, add to visited list
    update result
    add all unvistied neighbours to minHeap

    return result
    */
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<bool> visited(points.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>,  greater<pair<int, int>>> minHeap;
        int visitedCount = 0;
        int result=0;

        minHeap.push({0,0});

        while (visitedCount < points.size()) {
            auto [cost, u] = minHeap.top();
            minHeap.pop();
            
            if (visited[u]) {
                continue;
            }

            result += cost;
            visited[u] = true;
            visitedCount++;

            for (int i = 0; i < points.size(); i++) {
                if (!visited[i]) {
                    int dist = abs(points[u][0] - points[i][0]) +
           abs(points[u][1] - points[i][1]);
                    minHeap.push({dist, i});

                }

            }


        }

        return result;



        
    }
};
