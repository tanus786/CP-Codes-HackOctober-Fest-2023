class Solution:
    def union(self, head1,head2):
        # code here
        # return head of resultant linkedlist
        #union of two linked lists with only distinct elements

        #create a set to store the elements
        s = set()

        #traverse the first linked list and store the elements in the set
        temp = head1
        while temp:
            s.add(temp.data)
            temp = temp.next

        #traverse the second linked list and store the elements in the set
        temp = head2
        while temp:
            s.add(temp.data)
            temp = temp.next

        #create a new linked list with the elements in the set
        head = None
        for i in sorted(s):
            if head is None:
                head = Node(i)
                temp = head
            else:
                temp.next = Node(i)
                temp = temp.next

        return head
        