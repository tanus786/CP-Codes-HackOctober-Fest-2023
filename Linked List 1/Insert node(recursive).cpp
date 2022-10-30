/*
Insert node (recursive)
You have been given a linked list of integers. Your task is to write a function that inserts a node at a given position, 'pos'.

Note: Assume that the Indexing for the linked list always starts from 0.
If the given position 'pos' is greater than length of linked list, then you should return the same linked list without any change. And if position 'pos' is equal to length of input linked list, then insert the node at the last position.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the linked list separated by a single space. 
The second line of each test case contains two space separated integers, that denote the value of 'pos' and the data to be inserted respectively. 
 
Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format:
For each test case/query, print the resulting linked list of integers in a row, separated by a single space.
Output for every test case will be printed in a separate line.
You don't need to print explicitly, it has been taken care of.

Constraints:
1 <= t <= 20
0 <= length of linked list <= 10^4
0 <= pos, data to be inserted <= 2^31 - 1

Time Limit: 1 second

Sample Input 1:
1
3 4 5 2 6 1 9 -1
3 100

Sample Output 1:
3 4 5 100 2 6 1 9


Sample Input 2:
1 
3 4 5 2 6 1 9 -1
0 20

Sample Output 2:
20 3 4 5 2 6 1 9
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

Node* insertNode(Node *head, int pos, int data) {
	// Write your code here
    if(pos == 0 and head) {
        Node *newNode = new Node(data);
        newNode -> next = head;
        return newNode;
    }	
    // corner case
    if(head == NULL) {
        return head;
    }
    
    head -> next = insertNode(head -> next, pos - 1, data);
    return head;
    
}

// Time Complexity : O(n)
// Auxillary Space : O(n) -> For call Stack
