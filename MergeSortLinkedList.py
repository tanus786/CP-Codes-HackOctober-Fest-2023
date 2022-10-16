from sys import stdin, setrecursionlimit
setrecursionlimit(10 ** 6)

#Following is the Node class already written for the Linked List
class Node :
    def __init__(self, data) :
        self.data = data
        self.next = None


def sortedMerge(a,b):
    result = None
        
    # Base cases
    if a == None:
        return b
    if b == None:
        return a
            
    # pick either a or b and recur..
    if a.data <= b.data:
        result = a
        result.next = sortedMerge(a.next, b)
    else:
        result = b
        result.next = sortedMerge(a, b.next)
    return result
def getMiddle(head):
    if (head == None):
        return head

    slow = head
    fast = head

    while (fast.next != None and
            fast.next.next != None):
        slow = slow.next
        fast = fast.next.next
            
    return slow
def mergeSort(head) :
	#Your code goes here
        # Base case if head is None
    if head == None or head.next == None:
        return head

    # get the middle of the list
    middle = getMiddle(head)
    nexttomiddle = middle.next

    # set the next of middle node to None
    middle.next = None

    # Apply mergeSort on left list
    left = mergeSort(head)
        
    # Apply mergeSort on right list
    right = mergeSort(nexttomiddle)

    # Merge the left and right lists
    sortedlist = sortedMerge(left, right)
    return sortedlist



























#Taking Input Using Fast I/O
def takeInput() :
    head = None
    tail = None

    datas = list(map(int, stdin.readline().rstrip().split(" ")))

    i = 0
    while (i < len(datas)) and (datas[i] != -1) :
        data = datas[i]
        newNode = Node(data)

        if head is None :
            head = newNode
            tail = newNode

        else :
            tail.next = newNode
            tail = newNode

        i += 1

    return head


def printLinkedList(head) :

    while head is not None :
        print(head.data, end = " ")
        head = head.next

    print()
head = takeInput()

newHead = mergeSort(head)
printLinkedList(newHead)
