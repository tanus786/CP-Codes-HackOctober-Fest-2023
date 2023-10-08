from typing import List
from queue import Queue
class Solution:
    #Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
       
        # code here
        visited = [False] * V
        q = Queue()
        q.put(0)
        visited[0] = True
        res = []
        while not q.empty():
            node = q.get()
            res.append(node)
            for i in adj[node]:
                if not visited[i]:
                    q.put(i)
                    visited[i] = True
        return res
        