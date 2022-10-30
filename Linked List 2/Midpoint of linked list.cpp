/*
Midpoint of LL
For a given singly linked list of integers, find and return the node present at the middle of the list.

Note : If the length of the singly linked list is even, then return the first middle node.

Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective data values are, 20 and 30. We return the first node with data 20.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space. 

Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output Format :
For each test case/query, print the data value of the node at the middle of the given list.
Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5 
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
1
1 2 3 4 5 -1

Sample Output 1 :
3


Sample Input 2 :
2 
-1
1 2 3 4 -1

Sample Output 2 :
2
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

Node *midPoint(Node *head) {	
   //corner case 
   if(head == NULL or head -> next == NULL) {
       return head;
   } 
    
   Node *slow = head;
   Node *fast = head -> next;
   
   while(fast and fast -> next) {
       slow = slow -> next;
       fast = fast -> next -> next;
   } 
    
   return slow;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
