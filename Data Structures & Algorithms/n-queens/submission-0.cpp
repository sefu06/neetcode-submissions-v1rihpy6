class Solution {
public:
vector<vector<string>> result;
vector<int> queens;
    vector<vector<string>> solveNQueens(int n) {
        
    
                vector<string> curr;
                dfs(n, curr, 0);
                queens.clear();

        return result;
        
    }

void dfs(int boardSize, vector<string>& curr, int row) {
    
    

    if (row==boardSize) {
        result.push_back(curr);

    }

    for (int column = 0; column < boardSize; column++) {

    if (!canAttack(row, column, queens)) {
        string r = "";
        
        for (int i = 0; i < boardSize; i++) {
            if (i == column) {
                r += "Q";

            } else {
                r += ".";
            }

        }

        curr.push_back(r);
        queens.push_back(column);
        dfs(boardSize, curr, row+1);
        curr.pop_back();
        queens.pop_back();

    }
        


    }

}

bool canAttack(int row, int column, vector<int>& queens){
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = queens[prevRow];
        if (abs(row - prevRow) == abs(column - prevCol) || row == prevRow || column == prevCol) {
            return true;

        }
       
    }

    return false;

}
};
