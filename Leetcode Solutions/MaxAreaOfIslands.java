package com.arrays;

public class MaxAreaOfIslands {
    public int maxAreaOfIsland(int[][] grid) 
    {
    	int res=0;
    	for(int i=0; i<grid.length;i++)
    		for(int j=0; j<grid[i].length ; j++)
    			if(grid[i][j]==1)
    				res= Math.max(res, dfs(grid, i,j));
    	return res;
    }

	private int dfs(int[][] grid, int i, int j) 
	{
		if(i<0 || i>= grid.length || j<0 || j>=grid[i].length || grid[i][j] ==0)
			return 0;
		int count=1;
		//unset the grid[i][j] to prevent double counting
		grid[i][j]=0;
		count += dfs(grid, i, j+1);
		count += dfs(grid, i, j-1);
		count += dfs(grid, i+1, j);
		count += dfs(grid, i-1, j);
		
		return count;
	}
	
}
