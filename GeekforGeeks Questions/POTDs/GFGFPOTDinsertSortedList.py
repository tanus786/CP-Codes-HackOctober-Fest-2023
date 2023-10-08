class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    def sortedInsert(self, head1, key):
        new_node = Node(key)
        
        # if the linked list is empty, make the new node the head
        if not head1:
            head1 = new_node
            return head1
        
        # if the new node is smaller than the head, make it the new head
        if new_node.data < head1.data:
            new_node.next = head1
            head1 = new_node
            return head1
        
        # traverse the linked list to find the correct position to insert the new node
        curr = head1
        while curr.next and curr.next.data < new_node.data:
            curr = curr.next
        
        # insert the new node
        new_node.next = curr.next
        curr.next = new_node
        
        return head1
