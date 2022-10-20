import java.util.*;
//In this code rat have to find shortest way to reach from starting corner to opposite ending corner which is shortest path to reach
//applying recursion to solve it

class Solution {

    //applying recursion to solve this problem to choose shoertest way
    public static void solve(int i,int j,int[][] a,int n,ArrayList<String> ans,String move,int[][]vis) {
        //codition to terminate if i&j rech at boundary of matrix
        if (i==n-1 && j==n-1){
            ans.add(move);
            return ;     
        }

        //D ->for down , R-> for right ,L -> for left , U -> for up 
        //selecting shortest way to go by conditions

        //if down-ward have 1 than move 
        if (i+1<n && vis[i+1][j]==0 && a[i+1][j]==1 ){
            vis[i][j] = 1;
            solve(i+1, j, a, n, ans, move+"D", vis);
            vis[i][j] = 0;
        }
        //if left side  have 1 than move 
        if (j-1>0 && vis[i][j-1]==0 && a[i][j-1]==1 ){
            vis[i][j] = 1;
            solve(i, j-1, a, n, ans, move+"L", vis);
            vis[i][j] = 0;
        }
        //if right side  have 1 than move   
        if (j+1<n && vis[i][j+1]==0 && a[i][j+1]==1 ){
            vis[i][j] = 1;
            solve(i, j+1, a, n, ans, move+"R", vis);
            vis[i][j] = 0;
        }
        //if up side have 1 than move
        if (i-1>0 && vis[i-1][j]==0 && a[i-1][j]==1 ){
            vis[i][j] = 1;
            solve(i-1, j, a, n, ans, move+"U", vis);
            vis[i][j] = 0;
        }

    }
    //class to create a new matrix to add visite "1" or "0" not visite in main recive method
    public static ArrayList<String> find(int[][] a,int n) {
         int[] [] vis= new int[n][n];
         for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                vis[i][j] = 0;
         }
    }
    //calling the solve method
    ArrayList<String> ans = new ArrayList<>();
    if (a[0][0] ==1) solve(0,0,a,n,ans,"",vis);
    return ans;
}
}

public class rat {
    public static void main(String[] args) {
        int n= 4;
        // code take input in matrix form 
        //which is in 0 or 1  and rat will decide what is the minimum rout to go at end corner 
        //1 is for move and 0 is don't move

        int[][] a={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
        Solution obj=new Solution();
        ArrayList<String> res=obj.find(a, n);

        //print output in form of DRLU which is choice of rat to move in shortest way to reach at opposite corner
        if(res.size()>0) {
            for (int i=0; i<res.size(); i++) {
                System.out.print(res.get(i)+" ");
                System.out.println();
            }
        }else{
            System.out.println(-1);
        }
        //output will be 2 because of same same shortest distance->
        //DDRDRR and DRDDRR
    }
}
