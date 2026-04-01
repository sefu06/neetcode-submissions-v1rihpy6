class Solution {
    /*
   loop through the border and see if there are any 0s. add to a stack. 
   perform dfs on each element of the stack. 

   dfs marks the Os that are reachale by the edge O as "#"

   then we loop around the entire board and if the position is # we change it
   back to O and if its O we change it to X.
       */
public:
int directions[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        stack<pair<int, int>> stack;

        for (int r = 0; r < ROWS; r++) {
            if (board[r][0]== 'O') {
                stack.push({r, 0});
            }

            if (board[r][COLS-1] == 'O') {
                stack.push({r, COLS-1});

            }

        }

        for (int c = 1; c < COLS-1; c++) {
            if (board[0][c]=='O') {
                stack.push({0, c});

            }

            if (board[ROWS-1][c]=='O') {
                stack.push({ROWS-1, c});

            }

        }

        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            dfs(board, top.first, top.second);

        }

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c]=='#') {
                    board[r][c] = 'O';

                }

                else if (board[r][c] == 'O') {
                    board[r][c] = 'X';

                }

            }
        }
        
    }

    void dfs(vector<vector<char>>& board, int row, int col) {

        if (row < 0 || col < 0 || 
    row >= board.size() || col >= board[0].size() || 
    board[row][col] != 'O') {
            return;

        }

        board[row][col] = '#';

        for (int i = 0; i < 4; i++) {
            dfs(board, row + directions[i][0], col + directions[i][1]);

        }


    }
};
