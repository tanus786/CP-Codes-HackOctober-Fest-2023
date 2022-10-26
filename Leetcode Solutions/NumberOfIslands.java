package com.arrays;

public class NumberOfIslands {
    public int numIslands(char[][] grid) {
    	int res=0;
    	if(grid.length==0 || grid==null)
    		return res;
    	
    	for(int i=0; i<grid.length; i++)
    		for(int j=0; j<grid[i].length; i++)
    			if(grid[i][j]== '1')
    				res += dfs(grid, i,j);
    	return res;
    }

	private int dfs(char[][] grid, int i, int j) 
	{
		//Checking the boundary 
		if(i<0 || i>= grid.length || j<0 || j>= grid[i].length || grid[i][j]=='0')
			return 0;
		
		//Unsetting the grid[i][j]
		grid[i][j]='0';
		dfs(grid, i,j-1);
		dfs(grid, i,j+1);
		dfs(grid, i+1,j);
		dfs(grid, i-1,j);
		return 1;	//We count here for every island
	}
}
