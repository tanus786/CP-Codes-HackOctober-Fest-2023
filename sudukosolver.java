//parent class for suduko solve
public class suduko {
    public static boolean solve(char[][] board){
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
              
                if(board[i][j]=='.'){
                  
                    for (char k='1'; k<='9'; k++) {
                         if(isTrue(board,i,j,k)){

                            board[i][j] = k;
                            if(solve(board)){
                                return true;
                            }else{
                                board[i][j] ='.';
                            }
                         }
                    }
                    return false;
                }
            }
        }
       return true;
    }
  //class for creating board of suduko and call to suduko class
    public static boolean isTrue(char[][] board, int row, int col, char k) {
     for (int i=0; i<9; i++) {
        if (board[row][i]==k) return false;
  
        if(board[i][col]==k) return false;
        
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]==k) return false;
        
    }
    return true;

}
  //main method
    public static void main(String[] args) {
        char[][] board= {
            {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
            {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
            {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
            {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
            {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
            {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
            {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
            {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
            {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
            };
//      calling solve to run program
        solve(board);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }

    }
}
