/*
Delete node
You have been given a linked list of integers. Your task is to write a function that deletes a node from a given position, 'POS'.

Note : Assume that the Indexing for the linked list always starts from 0.

If the position is greater than or equal to the length of the linked list, you should return the same linked list without any change.

Input format :
The first line contains an Integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the linked list separated by a single space. 
The second line of each test case contains the integer value of 'POS'. It denotes the position in the linked list from where the node has to be deleted.
 
Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.
Output for every test case will be printed in a separate line.

Note: You are not required to print the output, it has already been taken care of. Just implement the function. 

Constraints :
1 <= T <= 10^2
0 <= N <= 10^5
POS >= 0

Time Limit: 1sec

Sample Input 1 :
1 
3 4 5 2 6 1 9 -1
3

Sample Output 1 :
3 4 5 6 1 9


Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
10 20 30 40 50 60 -1
7

Sample Output 2 :
4 5 2 6 1 9
10 20 30 40 50 60
*/

/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
/* Recursive
Node *deleteNode(Node *head, int pos) {
    if(head == NULL) {
        return NULL;
    }
    if(pos == 0 and head) {
        return head -> next;
    } else if(pos == 0) {
        Node *newNode = head -> next;
        delete head;
        return newNode;
    } else {
        head -> next = deleteNode(head -> next, pos - 1);
        return head;
    }
}
 Time Complexity : O(n)
 Auxillary Space : O(n)
*/

Node *deleteNode(Node *head, int pos) {
    // Write your code here.
    int count = 0;
    Node *ptr = head;
    
    //corner case
    if(pos == 0) {
        if(head == NULL) {
        	return NULL;
        }
        return head -> next;
    }

    while(ptr) {
        if(count == pos - 1) {
            if(ptr -> next == NULL) {
                return head;
            }
            ptr -> next = ptr -> next -> next;
            return head;
        }
        count++;
        ptr = ptr -> next;
    }
    return head;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)

