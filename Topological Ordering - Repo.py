from collections import deque

def topologicalOrder(edges, vertices):
  
  indegree=dict() # To store indegree of the nodes
  graph=dict() # To store the neighbours of a nodes
  
  #Now, we have to insert all nodes in the above dictionaries
  #We have to initialize each node in above dictionaries as:
  #indegree with 0
  #graph with empty list
  
  for node in range(vertices):
    indegree[node]=0
    graph[node]=list()
    
  for edge in edges:
    parent=edge[0]
    child=edge[1]
    indegree[child]+=1
    graph[parent].append(child)
  
  sources=deque()
  
  for key,value in indegree.items():
    if value==0:
      sources.append(key)
  
  sortedOrder=[] #Answer
  
  while sources:
    curr_node=sources.popleft()
    sortedOrder.append(curr_node)
    for nbr in graph[curr_node]:
      indegree[nbr]-=1 #Decreasing indegree of neighbour
      if indegree[nbr]==0:
        sources.append(nbr)
        
  if len(sortedOrder)==vertices: 
    return sortedOrder
  else:
    return [] #Return empty list if topological sort is not possible

if __name__=='__main__':
  edges=[[6,4],[6,2],[5,3],[5,4],[3,0],[3,1],[3,2]]
  vertices=7 #Number of vertices (nodes)
  ans=topologicalOrder(edges, vertices)
  print(ans)