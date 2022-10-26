'''
206. Reverse Linked List
https://leetcode.com/problems/reverse-linked-list/

Given the head of a singly linked list, reverse the list, and return the reversed list.
'''

def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    temp = head
    prevTemp = None
    
    while temp is not None:
        immediateNext = temp.next
        temp.next = prevTemp
        prevTemp = temp
        temp = immediateNext
    return prevTemp