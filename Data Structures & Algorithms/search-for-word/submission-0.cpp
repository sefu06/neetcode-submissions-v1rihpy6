class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Try starting from every cell
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }
        return false;
    
    }
    

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int index) {
        if (index == word.size()) {
            return true;

        }

          if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            board[r][c] != word[index]) {
            return false;
        }

           
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions
        bool found =
            dfs(board, word, r + 1, c, index + 1) ||
            dfs(board, word, r - 1, c, index + 1) ||
            dfs(board, word, r, c + 1, index + 1) ||
            dfs(board, word, r, c - 1, index + 1);

        // Backtrack (restore cell)
        board[r][c] = temp;

        return found;

    }
    
};
