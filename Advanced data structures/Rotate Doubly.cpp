#include<iostream>
using namespace std;

class Node
{
	public:
		char data;
		Node* next;
		Node* pre;
	Node(int data)
	{
		this->data=data;
		pre=NULL;
		next=NULL;
	}
};

void insertAtHead(Node* &head, int data)
{
	Node* n = new Node(data);
	if(head==NULL)
	{
		head=n;
		return;
	}
	n->next=head;
	head->pre=n;
	head=n;
	return;
}
void insertAtTail(Node* &head, int data)
{
	if(head==NULL)
	{
		insertAtHead(head,data);
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	Node* n=new Node(data);
	temp->next=n;
	n->pre=temp;
	return;
}
void display(Node* head)
{
	while(head!=NULL)
	{
		cout << head->data << "-->";
		head=head->next;
	}
	cout << "NULL\n";
}

void rotateByN(Node* &head, int pos)
{
	// return without any changes if position is 0.
	if(pos==0) return;

	// Finding last node.
	Node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	// making the list circular.
	temp->next=head;
	head->pre=temp;

	// move head and temp by the given position.
	int count=1;
	while(count<=pos)
	{
		head=head->next;
		temp=temp->next;
		count++;
	}

	// now again make list un-circular.
	temp->next=NULL;
	head->pre=NULL;
}
int main()
{
	Node* head=NULL;
	insertAtTail(head,'a');
	insertAtTail(head,'b');
	insertAtTail(head,'c');
	insertAtTail(head,'d');
	insertAtTail(head,'e');

	int n=2;
	cout << "\nBefore Rotation : \n";
	display(head);
	rotateByN(head,n);
	cout << "\nAfter Rotation : \n";
	display(head);
	cout << "\n\n";

	return 0;
}
