class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        

        //checks duplicates for rows

        for (int i = 0; i < board.size(); i++) {
            unordered_set<char> row;
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    auto res = row.insert(board[i][j]);

                    if (res.second == false) {
                    return false;

                }
                }

                
                
            }

            }


//check colums for duplicates
        for (int j = 0; j < 9; j++){
            unordered_set<char> col;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
            auto res = col.insert(board[i][j]);

            if (res.second == false) {
                    return false;

                }
                }

                


        }

        }

        //check squares
        for (int i = 0; i < 9; i+=3) {
            
            for (int j = 0; j < 9; j+=3) {
                unordered_set<char> square;

                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i + k][j + l] != '.') {
                            auto res = square.insert(board[i + k][j + l]);

                            if (res.second == false) {

                    return false;

                }
                }

                



                    }
                }

                

            }
        }

        return true;



        
    }
};
