class Solution {
    /*
    ok for this problem we should to a dfs for sure. 

    pacific is heights[0][0-COLS-1] and heights[0-ROWS-1][0];
    atlantic is heights[ROWS-1][0-COLS-1] and heights[0-ROWS-1][COLS-1];

    loop through all the cells that have acess to the pacific and perofrom dfs
    on them, with base case being it reaches a cell with access to the atlantic.
    */
public:
vector<vector<int>> result;
int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

        

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        
        vector<vector<bool>> pacificVisited(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlanticVisited(ROWS, vector<bool>(COLS, false));

        for (int c = 0; c < COLS; c++) {
            dfs(heights, 0, c, pacificVisited);

        }

        for (int r = 0; r < ROWS; r++) {
            dfs(heights, r, 0, pacificVisited);

        }

        for (int c = 0; c < COLS; c++) {
            dfs(heights, ROWS-1, c, atlanticVisited);

        }

        for (int r=0; r < ROWS; r++) {
            dfs(heights, r, COLS-1, atlanticVisited);

        }

        for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
        if (pacificVisited[r][c] && atlanticVisited[r][c]) {
            result.push_back({r, c});
        }
    }
}





        return result;



        
    }

    void dfs(vector<vector<int>>& heights, int r, int c,  vector<vector<bool>>& visited) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        if (visited[r][c]) return;
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r+directions[i][0];
            int nc = c+directions[i][1];

        if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || heights[nr][nc] < heights[r][c] ) {
            continue;

        }

        dfs(heights, nr, nc, visited);
        
        }

    }


};
