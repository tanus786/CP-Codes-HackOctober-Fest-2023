Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Solution:

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c){
        for(int i=0;i<9;i++)
            if(i!=c&&board[r][i]==board[r][c]) return false;
        for(int i=0;i<9;i++)
            if(i!=r&&board[i][c]==board[r][c]) return false;
        int smi=r/3*3, smj=c/3*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if((smi+i==r)&&(smj+j==c)) continue;
                if(board[smi+i][smj+j]==board[r][c]) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(isValid(board, i, j)==false) return false;
                }
            }
        }
        return true;
    }
};
