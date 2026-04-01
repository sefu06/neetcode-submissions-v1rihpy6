class Solution {
public:
 int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int maxIslandSize = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    maxIslandSize = max(maxIslandSize, dfs(grid, r, c));
                

                }

            }
        }

        return maxIslandSize;

        
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
        
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0) {
            return 0;
        }
        
        grid[r][c] = 0;
        int area = 1;
        


        for (int i = 0; i < 4; i++) {
            area += dfs(grid, r + directions[i][0], c + directions[i][1]);

        }

        return area;



    }
};
