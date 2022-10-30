/*
Swap two Nodes of LL
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th' and 'j-th' positions.
Note : Remember, the nodes themselves must be swapped and not the datas.
No need to print the list, it has already been taken care. Only return the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case or query contains the elements of the singly linked list separated by a single space.
The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element

Output format :
For each test case/query, print the elements of the updated singly linked list.
Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M
0 <= j < M

Time Limit: 1sec

Sample Input 1 :
1
3 4 5 2 6 1 9 -1
3 4

Sample Output 1 :
3 4 5 6 2 1 9 


Sample Input 2 :
2
10 20 30 40 -1
1 2
70 80 90 25 65 85 90 -1
0 6

Sample Output 2 :
10 30 20 40 
90 80 90 25 65 85 70 
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

Node *swapNodes(Node *head, int i, int j){
	Node *curr_ptr = head;
    Node *prev_ptr = NULL;
    Node *prev_i = NULL;
    Node *prev_j = NULL;
    Node *curr_i = NULL;
    Node *curr_j = NULL;
    
    int counter = 0;
    
    // No swapping in this case
    if(i == j) {
        return head;
    }
    
    
    while(curr_ptr) {
        if(counter == i) {
            prev_i = prev_ptr;
            curr_i = curr_ptr;
        } else if (counter == j) {
            prev_j = prev_ptr;
            curr_j = curr_ptr;
        }
        prev_ptr = curr_ptr;
        curr_ptr = curr_ptr -> next;
        counter++;
    }
    
    if(prev_i) {
        prev_i -> next = curr_j;
    } else {
        head = curr_j;
    }
    
    if(prev_j) {
        prev_j -> next = curr_i;
    } else {
        head = curr_i;
    }
    
    Node *temp = curr_j -> next;
    curr_j -> next = curr_i -> next;
    curr_i -> next = temp;
    
    return head;
}

// Time Complexity : O(n)
// Auxillary Space : O(1)
