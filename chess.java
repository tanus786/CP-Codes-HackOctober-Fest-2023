import java.util.*;
//class to solve how many way a quen can make steps on board
class Solution {
  //recursive method
    void solve(int col,int n,char[][] board,List<List<String>> res,int[] downD,int[] left,int[] upD)
    {
        if (col==n){
            res.add(construct(board));
            return;
        }
        for (int row = 0; row < board.length; row++) {
            if(downD[row+col]==0 && left[row]==0 && upD[board.length-1+col-row]==0){
                downD[row+col]=1;
                left[row]=1;
                upD[board.length-1+col-row]=1;
                board[row][col]='Q';
                solve(col+1,n,board,res,downD,left,upD);
                downD[row+col]=0;
                left[row]=0;
                upD[board.length-1+col-row]=0;
                board[row][col]='.';
            }
        }
      }
    List<String> construct(char[][] board){
               List<String> res=new LinkedList<>();
               for (int i=0; i<board.length; i++) {
                String s=new String(board[i]);
                res.add(s);
               }
               return res;
    }
  //creating chess board 
    List<List<String>> solveQn(int n){
        char[][] board=new char[n][n];
        for (int i=0; i<n; i++) {
            for ( int j=0; j<n; j++) {
                board[i][j]='.';
            }
        }
        List<List<String>> res=new ArrayList<>();
        int[] downD=new int[2*n-1];
        int[] left=new int[n];
        int[] upD=new int[2*n-1];
      //passing chess oard into solve by calling
        solve(0,n,board,res,downD,left,upD);

        return res;
    }
}
//main class, method 
public class chess {
    public static void main(String[] args) {
        int n=5;
      //creating constructor and class call
        Solution g=new Solution();
        List<List<String>> t= g.solveQn(n);
      //displaying output 
        int c=1;
        for (List<String> i:t) {
            System.out.println(c+"ans->");
            for(String s:i) {
            System.out.println(s);
         
        }
        c++;
        }
           
    }
}
