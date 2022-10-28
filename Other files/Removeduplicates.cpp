#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void removeDuplicates(struct Node* head)
{
	struct Node* c = head;
	struct Node* next_next;
	if (c == NULL)
	return;
	while (c->next != NULL)
	{
	    if (c->data == c->next->data)
	    {			
		    next_next = c->next->next;
		    free(c->next);
		    c->next = next_next;
	    }
	    else 
	    {
		    c = c->next;
	    }
	}
}
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);	
	(*head_ref) = new_node;
}
void printList(struct Node *node)
{
	while (node!=NULL)
	{
	    printf("%d ", node->data);
	    node = node->next;
	}
}
int main()
{
	struct Node* head = NULL;
	push(&head, 4);
	push(&head, 3);
	push(&head, 3);
	push(&head, 2);
	push(&head, 2);
	push(&head, 2);									
	printf("\n Linked list before removing duplicates ");
	printList(head);
	removeDuplicates(head);
	printf("\n Linked list after removing duplicates ");		
	printList(head);			
}
