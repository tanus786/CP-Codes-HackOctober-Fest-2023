package com.hard;

public class LongestIncreasingInMatrix {
    public int longestIncreasingPath(int[][] matrix) {
    	if(matrix==null || matrix.length==0) return 0;
    	int rows= matrix.length, col= matrix[0].length, res=0;
    	//Creating a dp
    	int[][] dp= new int[rows][col];
    	for(int i=0; i<rows; i++) {
    		for(int j=0; j<col; j++){
    			if(dp[i][j]==0){
    				dfs(i,j,dp, matrix, Integer.MIN_VALUE);
    				res= Math.max(dp[i][j],res);
    			}
    		}
    	}
    	return res;
    }

	private int dfs(int i, int j, int[][] dp, int[][] matrix, int prev)
	{
		if(i<0 || i> matrix.length-1 || j<0 || j> matrix[0].length-1 || matrix[i][j]<=prev)
			return 0;
		//Checking if the dp has been evaluated before
		if(dp[i][j] !=0) return dp[i][j];
		
		int left= dfs(i, j-1, dp, matrix, matrix[i][j]);
		int right= dfs(i, j+1, dp, matrix, matrix[i][j]);
		int up= dfs(i-1, j, dp, matrix, matrix[i][j]);
		int down= dfs(i+1, j, dp, matrix, matrix[i][j]);
		
		dp[i][j]= Math.max(left, Math.max(right, Math.max(up, down)))+1;
		return dp[i][j];
	}
}
