''' https://leetcode.com/problems/merge-two-sorted-lists/

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

'''

def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    if list1 is None: return list2
    if list2 is None: return list1
    
    if (list1.val > list2.val):
        list1, list2 = list2, list1
        
    result = list1
    
    while (list1 != None and list2 != None):
        tempNode = None
        
        while (list1 != None and list1.val <= list2.val):
            tempNode = list1
            list1 = list1.next
        
        tempNode.next = list2
        list1, list2 = list2, list1
    
    return result