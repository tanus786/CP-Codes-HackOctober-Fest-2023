class Solution:
    def pairWiseSwap(self, head):
        # if the list is empty or has only one node, return the head
        if not head or not head.next:
            return head
        
        # initialize pointers for swapping
        prev = None
        curr = head
        
        # loop through the list and swap nodes pairwise
        while curr and curr.next:
            # save pointers to the next pair of nodes
            next_pair = curr.next.next
            
            # swap the current pair of nodes
            curr.next.next = curr
            if prev:
                prev.next = curr.next
            else:
                head = curr.next
            curr.next = next_pair
            
            # update pointers for the next iteration
            prev = curr
            curr = next_pair
        
        return head
