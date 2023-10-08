from collections import deque

class Solution:
    def shortestDistance(self, N, M, A, X, Y):
        # Define the directions: up, down, left, right
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        
        # Function to check if a cell is valid (within bounds and containing 1)
        def is_valid(x, y):
            return 0 <= x < N and 0 <= y < M and A[x][y] == 1
        
        # Initialize the queue for BFS and mark the starting point as visited
        queue = deque([(0, 0, 0)])
        visited = set([(0, 0)])
        
        # Perform BFS
        while queue:
            x, y, steps = queue.popleft()
            
            # Check if the current cell is the target cell (X, Y)
            if x == X and y == Y:
                return steps
            
            # Explore all possible directions from the current cell
            for dx, dy in directions:
                new_x, new_y = x + dx, y + dy
                
                # Check if the new cell is valid and not visited yet
                if is_valid(new_x, new_y) and (new_x, new_y) not in visited:
                    queue.append((new_x, new_y, steps + 1))
                    visited.add((new_x, new_y))
        
        # If the target (X, Y) is not reachable, return -1
        return -1
