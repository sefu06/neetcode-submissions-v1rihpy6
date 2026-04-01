class Solution {
    /*
    solution:
    we can use dijkstras to find the shortest path. but instead of weights
    of edges, it is the elevation of the block.

    initialize a min heap, perform dijkstras until we reach botton right
    block. keep track of the maximum height and then return that.


    */
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        int N = grid.size();


        set<pair<int, int>> visited;


        minHeap.push({grid[0][0], 0, 0});
        visited.insert({0,0});
        

        while(!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();

            int t = curr[0], r = curr[1], c = curr[2];

            if (r == N - 1 && c == N - 1) {
                return t;
            }


            for (int i = 0; i < 4; i++) {
                int newR = r + directions[i][0];
                int newC = c + directions[i][1];
                if (newR < 0 || newC < 0 || newR == N || newC == N || visited.count({newR, newC})) {

                    continue;

                }

                visited.insert({newR, newC});
                minHeap.push({max(t, grid[newR][newC]), newR, newC});
            }



        }

        
    }
};
