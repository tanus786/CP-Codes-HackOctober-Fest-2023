/*
Bubble Sort (Iterative) LinkedList
Given a singly linked list of integers, sort it using 'Bubble Sort.'

Note : No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the sorted singly linked list.
Output for every test case will be printed in a seperate line.

Constraints :
0 <= M <= 10^3
Where M is the size of the singly linked list.

Time Limit: 1sec

Sample Input 1 :
10 9 8 7 6 5 4 3 -1

Sample Output 1 :
 3 4 5 6 7 8 9 10 
 

Sample Input 2 :
10 -5 9 90 5 67 1 89 -1

Sample Output 2 :
-5 1 5 9 10 67 89 90 
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
    if(head == NULL) {
        return 0;
    }
    return 1 + length(head -> next);
}

Node *bubbleSort(Node *head) {
    
    for(int i = 0; length(head) > i; i++) { 
        Node *prev = NULL;
        Node *curr = head;
        while(curr -> next) {
            
            if(curr -> data > curr -> next -> data) {
                if(prev) {
                    Node *temp = curr -> next -> next;
                    curr -> next -> next = curr;
                    prev -> next = curr -> next;
                    curr -> next = temp;
                    prev = prev -> next;
                } else {
                    head = curr -> next;
                    curr -> next = head -> next;
                    head -> next = curr;
                    prev = head;
                }
            } else { 
                prev = curr;
                curr = curr -> next;
            }
        }
    }
    return head;
}

// Time Complexity : O(n^2)
// Auxillary Space : O(1)
