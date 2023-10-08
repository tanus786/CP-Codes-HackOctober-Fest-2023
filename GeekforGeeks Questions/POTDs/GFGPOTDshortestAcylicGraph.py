from typing import List
from collections import defaultdict
import heapq

class Solution:
    def shortestPath(self, n: int, m: int, edges: List[List[int]]) -> List[int]:
        # Initialize graph and distances
        graph = defaultdict(list)
        distance = [float('inf')] * n
        
        # Build the graph from the given edges
        for edge in edges:
            u, v, dist = edge[0], edge[1], edge[2]
            graph[u].append((v, dist))
        
        # Perform topological sort
        def topological_sort():
            visited = [False] * n
            stack = []
            for i in range(n):
                if not visited[i]:
                    dfs(i, visited, stack)
            return stack
        
        def dfs(node, visited, stack):
            visited[node] = True
            for neighbor, _ in graph[node]:
                if not visited[neighbor]:
                    dfs(neighbor, visited, stack)
            stack.append(node)
        
        # Get the topological order
        topological_order = topological_sort()
        
        # Set distance of src vertex to 0
        src = 0
        distance[src] = 0
        
        # Relaxation process
        while topological_order:
            node = topological_order.pop()
            if distance[node] != float('inf'):
                for neighbor, dist in graph[node]:
                    new_distance = distance[node] + dist
                    if new_distance < distance[neighbor]:
                        distance[neighbor] = new_distance
        
        # Format the result
        result = []
        for d in distance:
            result.append(d if d != float('inf') else -1)
        
        return result