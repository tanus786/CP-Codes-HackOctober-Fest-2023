/*
Length of LL (recursive)
Given a linked list, find and return the length of the given linked list recursively.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
First and the only line of each test case or query contains elements of the singly linked list separated by a single space. 

Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, print the length of the linked list.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 20
0 <= N <= 10^4

Time Limit: 1 sec

Sample Input 1:
1 
3 4 5 2 6 1 9 -1

Sample Output 1:
7
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

int length(Node *head) {
    // Write your code here
    //corner case
    if(head == NULL) {
        return 0;
    }
    return length(head -> next) + 1;
}
// Time Complexity : O(n)
// Auxillary Space : O(n)
