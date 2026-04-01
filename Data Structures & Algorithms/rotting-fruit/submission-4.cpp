class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 0;
        queue<pair<int, int>> q;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }

            }

        }
       

        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                auto front = q.front();
                q.pop();


                for (int j = 0; j < 4; j++) {
                    int nr = front.first + directions[j][0];
                    int nc = front.second + directions[j][1];


                    if (nr >= grid.size() || nr < 0 || nc >= grid[0].size() || nc < 0 || grid[nr][nc] != 1) {
                        continue;

                    }


                    grid[nr][nc] = 2;
                    q.push({nr, nc});


                }

            }

            if (!q.empty()) {
                result++;

            }
        }

        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    return -1;

                }

            }
        }
        return result;
    }
};
