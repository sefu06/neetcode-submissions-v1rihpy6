class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});

                }

            }

        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = front.first + directions[i][0];
                int nc = front.second + directions[i][1];

                if (nr >= grid.size() | nr < 0 | nc >= grid[0].size() | nc  < 0 | grid [nr][nc] != 2147483647) {
                    continue;
                }

                grid[nr][nc] = grid[front.first][front.second] + 1;

                q.push({nr, nc});

            }

        }



        
    }
};
