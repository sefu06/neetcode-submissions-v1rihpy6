class Solution {
public:
int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int maxArea = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1){
                    maxArea = max(maxArea, dfs(grid, r, c));
                }
            }
        }

        return maxArea;
        
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {

        if (r < 0 | c < 0 | r >= grid.size() | c >= grid[0].size() | grid[r][c] == 0) {
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
