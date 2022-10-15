class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        //Tranversing the given sudoku
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                if(board[i][j] == '.') {    //blank found
                    
                    for(char c = '1';c <= '9'; c++) {   //trying all the possible numbers from 1-9
                        if(isValid(board,i,j,c)) {
                            board[i][j] = c;
                            
                            if(solve(board) == true)  //checking for the next blank 
                                return true;
                            else
                                board[i][j] = '.';  //if blank cannot be filled after checking then revert the changes
                        }
                    }
                    return false;
                }
            }
        }
        return true;    //if everything is filled then return true
    }
    
    bool isValid(vector<vector<char>>& board , int row , int col , char c) {
        for(int i=0;i<9;i++) {
            if(board[row][i] == c)  //checking row if the value already there
                return false;
            if(board[i][col] == c)  //checking column if value already there
                return false;
            //checking the 3X3 sub box where the blank value is present to check if element is there
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) 
                return false;
        }
        return true;
    }
};
