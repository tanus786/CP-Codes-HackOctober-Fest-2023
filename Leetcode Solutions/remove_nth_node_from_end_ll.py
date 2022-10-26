'''
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

'''
def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
    ptr1 = ptr2 = head
    
    for i in range(n):
        ptr1 = ptr1.next
    
    if not ptr1:
        return ptr2.next

    while ptr1.next is not None:
        ptr2 = ptr2.next
        ptr1 = ptr1.next
    ptr2.next = ptr2.next.next
    
    return head