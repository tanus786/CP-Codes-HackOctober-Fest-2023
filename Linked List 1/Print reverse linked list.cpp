/*
Print Reverse LinkedList
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.

Note : You can’t change any of the pointers in the linked list, just print it in the reverse order.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Constraints : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case, print the singly linked list of integers in a reverse fashion, in a row, separated by a single space.
Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^3
Time Limit: 1sec

Where 'M' is the size of the singly linked list.

Sample Input 1 :
1
1 2 3 4 5 -1

Sample Output 1 :
5 4 3 2 1


Sample Input 2 :
2
1 2 3 -1
10 20 30 40 50 -1

Sample Output 2 :
3 2 1
50 40 30 20 10
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
/*
void print(Node *head) {
    
    for(;head;) {
        cout << head -> data << " ";
        head = head -> next;
    }
}
void printReverse(Node *head){
    //Write your code here
    //corner case
    if(head == NULL) {
        print(head);
    }
	
    //Node *tail = head;
    Node *ptr = head;
    Node *prev = NULL;
    Node *next = NULL;
    
    for(;ptr;) {
        next = ptr -> next;
        ptr -> next = prev;
        
        prev = ptr;
        ptr = next;
    }
    
    print(prev);
}

// Time Complexity : O(n)
// Auxllary Space : O(1)

*/
void printReverse(Node *head) {
    // base case
    if(head == NULL) {
        return;
    }
    
    printReverse(head -> next);
    
    cout << head -> data << " "; 
    
}

// Time Complexity : O(n)
// Auxllary Space : O(n)
