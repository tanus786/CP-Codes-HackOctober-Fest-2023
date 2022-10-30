/*
kReverse
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, 
in the end, should be reversed as well.

Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5
For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5
For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
 
Note : No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the singly linked list separated by a single space.
The second line of input contains a single integer depicting the value of 'k'.
 
Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.
Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= k <= M

Time Limit:  1sec

Sample Input 1 :
1
1 2 3 4 5 6 7 8 9 10 -1
4

Sample Output 1 :
4 3 2 1 8 7 6 5 10 9


Sample Input 2 :
2
1 2 3 4 5 -1
0
10 20 30 40 -1
4

Sample Output 2 :
1 2 3 4 5 
40 30 20 10
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


Node *kReverse(Node *head, int k){
	//corner case
    if (head == NULL or k == 0) {
        return head;
    }
    
	Node *curr = head;
    Node *next = NULL;
    Node *prev = NULL;
    
    int count = 0;
    
    while(curr and count < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    // after the loop prev will be pointing at the first node of revesed group
	// and head will be at the last
    
    if(next) {
        head -> next = kReverse(next, k);
    }
    
    return prev;
}

// Time Complexity : O(n)  Since every node is visited
// Auxillary Space : O(n / k) -> At any point in time k many functions will be in the call stack 
