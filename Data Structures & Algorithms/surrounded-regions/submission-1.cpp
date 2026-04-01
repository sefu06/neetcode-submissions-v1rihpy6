class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {

        if (board.empty() || board[0].empty()) return;

        stack<pair<int, int>> stack;
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            if (board[r][0] == 'O') {
                stack.push({r, 0});

            }
        }

         for (int c = 1; c < cols; c++) {
            if (board[0][c] == 'O') {
                stack.push({0, c});

            }
        }

         for (int r = 1; r < rows; r++) {
            if (board[r][cols - 1] == 'O') {
                stack.push({r, cols-1});

            }
        }

         for (int c = 1; c < cols-1; c++) {
            if (board[rows-1][c] == 'O') {
                stack.push({rows-1, c});

            }
        }

        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            dfs(board, top.first, top.second);


        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == '#') {
                    board[r][c] = 'O';

                }else if (board[r][c] == 'O') {
                    board[r][c] = 'X';

                }

            }
        }
        
    }

    void dfs(vector<vector<char>>& board, int r, int c) {

        if (board[r][c] == '#') {
            return;

        }

        board[r][c] = '#';

        for (int i = 0; i < 4; i++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];

            if (nr < 0 || nr >= board.size() || nc < 0 || nc >= board[0].size() || board[nr][nc] != 'O') {
                continue;

            }

            dfs(board, nr, nc);

        }

    }
};
