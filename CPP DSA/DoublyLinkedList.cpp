/* 

	Name : harshwardhan tilekar
	Roll No : 23
	title = Design and implement a program for sorting two given lists
			and merging these two sorted lists of marks scored for technical 
			skill examination of recruitment cell using doubly linked list.

*/


#include <iostream>
using namespace std;
class node
{
	public: 
	int roll_No;  
	float marks;
	node *prev,*next;
};

class marks_list
{ 
	public:
	node *head ;
	int length ;

	marks_list()
	{ 
		head = NULL ;
		length = 0;
	}
	// to create new list
	void create();
	// to display list 
	void display();
	// to sorting in descending order 
	void sort(); 
	// swaping two nodes to sort
	node *swap(node *ptr1,node *ptr2);
	// to merge two sorted lists  
	void merge(marks_list l1,marks_list l2); 
}; 

void marks_list :: create()
{
	int size , roll_No;
	float marks ;
	node *curr ;
	
	cout<<"\n enter size of batch : ";
	cin>>size;
	
	length = size ;
	
	for (int i=0 ; i<size ; i++)
	{
	
		cout<<"\nEnter Roll No of Student "<<i+1<<" : ";
		cin>>roll_No;
		cout<<"Enter Marks of Student "<<i+1<<"   : ";
		cin>>marks;
		
		node *new_node = new node ;
		
		new_node->roll_No= roll_No;
		new_node->marks = marks ;
		new_node->prev = NULL ;
		new_node->next= NULL ;
	
		if(head == NULL)
		{
			head = new_node;
			curr = new_node;
		}
		else
		{
			curr->next = new_node ;
			new_node->prev = curr ;
			curr = new_node;
		}
	}
}

void marks_list ::display( )
{
	node *temp=head;
	cout<<"\t+---------------+";
	while(temp != NULL)
	{
		cout<<"\n\t|  Roll NO : "<<temp->roll_No<<endl;
		cout<<"\t|  Marks  : "<<temp->marks<<endl;
		temp = temp->next;
		cout<<"\t+---------------+";
	}
	
} 

void marks_list::sort()
{
	node **h;
	
	int swapped,i,j;
	
	for(i=0; i<length; i++)
	{
		h=&(head);
		swapped=0;
		for (j=0; j<length-i-1; j++)
		{
			node* p1=*h;  
			node* p2=p1->next;
						
			if( p1->marks < p2->marks )
			{
				*h=swap(p1,p2);
				swapped=1;
			}			
			h=&(*h)->next;
		}
		if(swapped==0)
		{
			break;
		}	
	}
}

node *marks_list::swap(node *ptr1,node *ptr2)
{
	
	if( ptr1->prev == NULL )
	{
		node *temp = ptr2->next;
		ptr2->next = ptr1;
		ptr2->prev = NULL;
		ptr1->next = temp;
		ptr1->prev = ptr2;
		temp->prev = ptr1;
		return ptr2;
	}
	else if(ptr2->next == NULL)
	{
		node *temp = ptr1->prev;
		ptr2->next = ptr1;
		ptr2->prev = temp;
		ptr1->prev = ptr2;
		ptr1->next = NULL;
		temp->next = ptr2;
		return ptr2;
	}
	else 
	{
		node *temp1 = ptr1->prev;
		node *temp2 = ptr2->next;
		ptr2->next = ptr1;
		ptr2->prev = temp1;
		ptr1->prev = ptr2;
		ptr1->next = temp2;
		temp2->prev = ptr1;
		temp1->next = ptr2;
		return ptr2;
	}
}

void marks_list ::merge(marks_list l1,marks_list l2)
{
	node *p = l1.head ;
	node *q = l2.head ;
	length = l1.length + l2.length ;	
	node *r = NULL ;
	
	if(p == NULL)
	{
		head = q ;
	}
	else if(q == NULL)
	{
		head = p ;
	}
	else if(p != NULL && q != NULL)
	{
		if(p->marks < q->marks)
		{
			r = p ;
			p = p->next ;
		}
		else
		{
			r = q ;
			q = q->next ;
		}
		head = r ;
	}
	
	while(p != NULL && q != NULL)
	{
		if(p->marks <= q->marks) 
		{
			r->next = p ;
			p->prev = r ;
			r = p ;
			p = p->next ;
		}
		else if(p->marks > q->marks)
		{
			r->next = q ;
			q->prev = r ;
			r = q ;
			q = q->next ;
		}
	}
	
	if(p == NULL )  
	{
		r->next = q ;
		q->prev = r ; 
	}
	else if(q == NULL)  
	{
		r->next = p ;
		p->prev = r ;
	}
}


int main()
{	
	marks_list l1,l2,l3;
	
	cout<<"\n\t Marks list 1 : ";
	l1.create() ;
	l1.sort();
	cout<<"\n\tSorted Marks list 1 : \n\n";
	l1.display();
	
	cout<<"\n\n\t Marks list 2 : ";
	l2.create() ;
	l2.sort();
	cout<<"\n\tSorted Marks list 2  : \n\n ";
	l2.display();
	
	l3.merge(l1,l2);
	l3.sort();
	cout<<"\n\n\tfinal sorted list after Merging two sorted lists\n";
	l3.display() ;
}


/*


         Marks list 1 :
 enter size of batch : 3

Enter Roll No of Student 1 : 1
Enter Marks of Student 1   : 12

Enter Roll No of Student 2 : 2
Enter Marks of Student 2   : 78

Enter Roll No of Student 3 : 3
Enter Marks of Student 3   : 56

        Sorted Marks list 1 :

        +---------------+
        |  Roll NO : 2
        |  Marks  : 78
        +---------------+
        |  Roll NO : 3
        |  Marks  : 56
        +---------------+
        |  Roll NO : 1
        |  Marks  : 12
        +---------------+

         Marks list 2 :
 enter size of batch : 4

Enter Roll No of Student 1 : 4
Enter Marks of Student 1   : 30

Enter Roll No of Student 2 : 5
Enter Marks of Student 2   : 60

Enter Roll No of Student 3 : 6
Enter Marks of Student 3   : 89

Enter Roll No of Student 4 : 7
Enter Marks of Student 4   : 14

        Sorted Marks list 2  :

        +---------------+
        |  Roll NO : 6
        |  Marks  : 89
        +---------------+
        |  Roll NO : 5
        |  Marks  : 60
        +---------------+
        |  Roll NO : 4
        |  Marks  : 30
        +---------------+
        |  Roll NO : 7
        |  Marks  : 14
        +---------------+

        final sorted list after Merging two sorted lists
        +---------------+
        |  Roll NO : 6
        |  Marks  : 89
        +---------------+
        |  Roll NO : 2
        |  Marks  : 78
        +---------------+
        |  Roll NO : 5
        |  Marks  : 60
        +---------------+
        |  Roll NO : 3
        |  Marks  : 56
        +---------------+
        |  Roll NO : 4
        |  Marks  : 30
        +---------------+
        |  Roll NO : 7
        |  Marks  : 14
        +---------------+
        |  Roll NO : 1
        |  Marks  : 12
        +---------------+
--------------------------------
Process exited after 48.89 seconds with return value 0
Press any key to continue . . .

*/
