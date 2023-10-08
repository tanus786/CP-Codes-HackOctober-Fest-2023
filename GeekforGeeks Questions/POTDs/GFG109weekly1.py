# You have an infinite nodes tree such that every node on height H has exactly H+1
# children nodes and node 1 as a root node at level 1. Nodes are numbered with
# consecutive integers at each level from left to right
# You are given an integer N as input. You have to find at which level node N exists in
# the tree

class Solution:
    def FindLevel(self,N):
        level = 1
        while N > 0:
            N -= level
            level += 1
        return level-1
        