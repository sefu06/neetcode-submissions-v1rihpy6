class Solution {
    /*
    my approach:
    loop through every square on the grid, add to the queue (for bfs).
    after weve gone throuhg every spquare on grid, we start bfs on the sqaures
    in the queue with a while loop and increment time. 

    then to check if all the fruit is rotted we run throuhg the grid again so see 
    if any 1s remain.
    */
public:
 int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 2) {
                    q.push({r, c});

                }

            }
        }

        while (!q.empty()) {
            int levelSize = q.size();
            bool newFruitRotted = false;

            for (int j = 0; j < levelSize; j++) {
            auto [r, c] = q.front();
            q.pop();
            

            for (int i = 0; i < 4; i++) {
                int nr = r+directions[i][0];
                int nc = c+directions[i][1];
                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || grid[nr][nc] != 1) {
                    continue;

                }

                grid[nr][nc] = 2;
                q.push({nr, nc});
                newFruitRotted = true;

            }
            }

            if (newFruitRotted) {
                time++;

            }
            

        }


        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    return -1;

                } 

            }
        }

        return time;



        
    }
};
