/*
Print ith node
For a given a singly linked list of integers and a position 'i', print the node data at the 'i-th' position.

Note : Assume that the Indexing for the singly linked list always starts from 0.

If the given position 'i',  is greater than the length of the given singly linked list, then don't print anything.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the singly linked list separated by a single space.
The second line contains the value of 'i'. It denotes the position in the given singly linked list.

Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, print the node data at the 'i-th' position of the linked list(if exists).
Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
i  >= 0

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3

Sample Output 1 :
2


Sample Input 2 :
2
3 4 5 2 6 1 9 -1
0
9 8 4 0 7 8 -1
3

Sample Output 2 :
3
0
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

void printIthNode(Node *head, int i){
    //Write your code here
    int count = 0;
    
    while(head) {
        count++;
        
        if(count == i + 1) {
            cout << head -> data;
            break;
        }
        
        head = head -> next;
    }
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
