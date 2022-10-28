package com.hard;

import java.util.PriorityQueue;

public class SwimInWater {
    public int swimInWater(int[][] grid) {
        if (grid == null) return -1;
        
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        PriorityQueue<int[]> pollMin = new PriorityQueue<>((a,b) -> a[2]-b[2]);
        int[][] travel = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // Add the first value : x, y, time
        pollMin.add(new int[]{0, 0, grid[0][0]});

        while(!pollMin.isEmpty()){
            // Get the min val from the top 
            int[] curr_data = pollMin.poll();
            visited[curr_data[0]][curr_data[1]] = true;

            // return if at last index
            if (curr_data[0] == grid.length && curr_data[1] == grid[0].length){
                return curr_data[2];
            }

            // Similar to BFS. Traverse the neighbours and add to priorityQueue
            for(int i = 0; i< travel.length; i++){
                int dx = curr_data[0] + travel[i][0];
                int dy = curr_data[0] + travel[0][i];

                // check boundary
                if(inBoundary(dx, dy, visited, grid)){
                    visited[dx][dy] = true;
                    // update time with max val
                    int time = curr_data[2] > grid[dx][dy] ? curr_data[2] : grid[dx][dy];
                    pollMin.add(new int[]{dx, dy, time});
                }
            }
        }
        return -1;
    }

    private boolean inBoundary(int dx, int dy, boolean[][] visited, int[][] grid) {
        if(dx >= grid.length || dx < 0 || dy < 0 || dy >= grid[0].length || visited[dx][dy])
            return false;
        return true;
    }
}
