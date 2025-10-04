/*
Find a Node in Linked List
You have been given a singly linked list of integers. Write a function that returns the index/position of integer data denoted by 'N' (if it exists). Return -1 otherwise.

Note : Assume that the Indexing for the singly linked list always starts from 0.

Input format :
The first line contains an Integer 'T' which denotes the number of test cases. 
The first line of each test case or query contains the elements of the singly linked list separated by a single space. 
The second line contains the integer value 'N'. It denotes the data to be searched in the given singly linked list.

Remember/Consider : While specifying the list elements for input, -1 indicates the end of the singly linked list and hence -1 would never be a list element.

Output format :
For each test case, return the index/position of 'N' in the singly linked list. Return -1, otherwise.
Output for every test case will be printed in a separate line.

Note: You do not need to print anything; it has already been taken care of. Just implement the given function.

Constraints :
1 <= T <= 10^2
0 <= M <= 10^5

Where 'M' is the size of the singly linked list.

Time Limit: 1 sec

Sample Input 1 :
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6

Sample Output 1 :
2
-1
Explanation for Sample Output 1:
In test case 1, 'N' = 5 appears at position 2 (0-based indexing) in the given linked list.
In test case 2, we can see that 'N' = 6 is not present in the given linked list.


Sample Input 2 :
2
1 -1
2
3 4 5 2 6 1 9 -1
6

Sample Output 2 :
-1
4

Explanation for Sample Output 2:
In test case 1, we can see that 'N' = 2 is not present in the given linked list.
In test case 2, 'N' = 6 appears at position 4 (0-based indexing) in the given linked list.
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

int findNode(Node *head, int n, int count = 0) {
    // Write your code here.
    
    // corner case 
	if(head == NULL) {
        return -1;
    }
    // base case
    if(n == head -> data) {
        return count;
    }
    
    return findNode(head -> next, n, count + 1);
}

// Time Complexity : O(n)
// Auxillary Spce : O(n)
