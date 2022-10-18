/*
	name = harshwardhan tilekar
	roll no = 23
	title = Design and implement a menu driven program for linear 
			and circular queue for food ordering
			using array and linked list.
*/

#include<iostream>
using namespace std;
#define n 10

class food_items
{	
	public :
		string item ;
		int price , quantity ;		
};

class food_items_node
{	
	public :
		string item ;
		int price , quantity ;
		food_items_node *link ;	
};

// Simple Queue Using array
class food_items_array
{
	
	public :		
		food_items queue[n]; 
		int front , rear ;
				
		food_items_array()
		{	
			front = -1 ;
			rear = -1 ;		
		}
		bool isfull()
		{	
			if(rear == n-1)
			{
				return true ;
			}
			else
				return false ;	
		}
		
		bool isempty()
		{	
			if(front == -1 && rear == -1)
			{
				return true ;
			}
			else 
				return false ;		
		}
		
		void enqueue(string i , int x , int q)
		{	
			if(isfull())
			{
				cout<<"\nList is FULL .\n";
			}
			else if(isempty())
			{ 
				front++;
				rear++ ;
				queue[rear].item = i ;
				queue[rear].price = x ;
				queue[rear].quantity = q ;
			}
			else
			{
				rear ++ ;
				queue[rear].item = i ;
				queue[rear].price = x ;
				queue[rear].quantity = q ;
			}
		}
		
		void dequeue()
		{		
			if(isempty())
			{
				cout<<"\nList is empty\n";
			}
			else if(front == rear)
			{ 	
				cout<<"\nDequeued item is : "<<queue[front].item;
				front = -1 ;
				rear = -1 ;
			}
			else
			{	
				cout<<"\nDequeued item is : "<<queue[front].item;
				front ++ ;	
			}
		}
		
		void display()
		{	
			int i ;	
			if(isempty())
			{	
				cout<<" Empty\n";	
			}
			
			else
			{
				for(i = front ; i <= rear ; i++)
				{
					cout<<queue[i].item<<"\t"<<queue[i].price<<" Rs * "<<queue[i].quantity<<endl;
				}
			}
		}
};


// Simple Queue Using Linked_List
class food_items_Linked_list
{
	public :
		food_items_node *front , *rear ;
		food_items_Linked_list()
		{	
			front = 0 ;
			rear = 0 ;	
		}
		
		bool isempty() ;
		void enqueue(string i , int x , int q) ;
		void dequeue() ;
		void display() ;		
};

bool food_items_Linked_list :: isempty()
{	
	if(front == 0 && rear == 0)
	{
		return true ;
	}	
	else
		return false ;
}

void food_items_Linked_list :: enqueue(string i , int x , int q)
{
	food_items_node *temp  = new food_items_node ;
	temp->item = i ;
	temp->price = x ;
	temp->quantity = q ;
	temp->link = NULL ;
	
	if(front == 0 && rear == 0 )
	{	
		front = temp ;
		rear = temp ;
	}
	
	else
	{	
		rear->link = temp ;
		rear = temp ;
	}
}

void food_items_Linked_list :: dequeue()
{	
	food_items_node *temp = front ;	
	cout<<"\nDequeud item is : "<<front->item ;
	front = front->link ;
	delete temp ;
}

void food_items_Linked_list :: display()
{	
	food_items_node *temp = front ;	
	if(isempty())
	{		
		cout<<" Empty\n";		
	}
	
	else
	{	
		while(temp != NULL)
		{		
			cout<<temp->item<<"\t"<<temp->price<<"Rs * "<<temp->quantity<<endl;
			temp = temp->link ;	
		}
	}
}

// circular queue using array
class food_items_circular_array
{	
	public :		
		food_items queue[n]; 
		int front , rear ;		
		food_items_circular_array()
		{		
			front = -1 ;
			rear = -1 ;	
		}
		bool isfull()
		{	
			if( ( front==0 && rear == n-1 ) || front == rear+1 )
			{
				return true ;
			}
			else
				return false ;		
		}
		
		bool isempty()
		{	
			if(front == -1 && rear == -1)
			{
				return true ;
			}	
			else 
				return false ;		
		}
		void enqueue(string i , int x , int q)
		{		
			if(isfull())
			{
				cout<<"\nList is FULL .\n";
			}
			else if(isempty())
			{ 
				front++;
				rear++ ;
				queue[rear].item = i ;
				queue[rear].price = x ;
				queue[rear].quantity = q ;
			}
			else
			{
				rear = (rear + 1)%n ;
				queue[rear].item = i ;
				queue[rear].price = x ;
				queue[rear].quantity = q ;
			}
		}
		
		void dequeue()
		{	
			if(isempty())
			{
				cout<<"\nList is empty\n";
			}
			else if(front == rear )
			{ 
				cout<<"\nDequeued item is : "<<queue[front].item;
				front = -1 ;
				rear = -1 ;
			}
			else
			{	
				cout<<"\nDequeued item is : "<<queue[front].item;
				front = (front+1)%n ;	
			}
		}
		
		void display()
		{
			int i = front ;			
			if(isempty() )
			{				
				cout<<" Empty\n";	
			}
			
			else
			{	
				while(i != rear)
				{
					cout<<queue[i].item<<"\t"<<queue[i].price<<"Rs * "<<queue[i].quantity<<endl;
					i = (i+1)%n ;
				}	
				cout<<queue[rear].item<<"\t"<<queue[rear].price<<"Rs * "<<queue[rear].quantity<<endl;
			}
		}	
};

// circular queue using linked list
class food_items_Linked_list_circular
{	
	public :	
		food_items_node *front , *rear ;		
		food_items_Linked_list_circular()
		{			
			front = NULL ;
			rear = NULL ;			
		}
		
		bool isempty() ;
		void enqueue(string i , int x , int q) ;
		void dequeue() ;
		void display() ;
		
};

bool food_items_Linked_list_circular :: isempty()
{	
	if(front == NULL && rear == NULL)
	{
		return true ;
	}	
	else
		return false ;
}

void food_items_Linked_list_circular :: enqueue(string i , int x , int q)
{	
	food_items_node *temp  = new food_items_node ;
	temp->item = i ;
	temp->price = x ;
	temp->quantity = q ;
	temp->link = NULL ;
	
	if(isempty())
	{
		front = temp ;
		rear = temp ;
		rear->link = front ;
	}
	else
	{	
		rear->link = temp ;
		rear = temp ;
		rear->link = front ;
	}
}

void food_items_Linked_list_circular :: dequeue()
{	
	food_items_node *temp = front ;	
	if(isempty())
	{
		cout<<"\nList is empty\n" ;
	}
	else if(front == rear)
	{
		cout<<"\nDequeud item is : "<<front->item ;
		front = rear = NULL ;
		delete temp ;
	}
	else
	{
		cout<<"\nDequeud element is : "<<front->item ;
		front = front->link ;
		rear->link = front ;
		delete temp ;
	}
}

void food_items_Linked_list_circular :: display()
{	
	food_items_node *temp = front ;
	if(isempty())
	{
		cout<<" Empty\n";	
	}
	else
	{	
		do
		{			
			cout<<temp->item<<"\t"<<temp->price<<"Rs * "<<temp->quantity<<endl;
			temp = temp->link ;			
		}
		while(temp != front) ;
	}
}



int main()
{	
	food_items_array obj1 ;
	food_items_Linked_list obj2 ;
	food_items_circular_array obj3 ;
	food_items_Linked_list_circular obj4 ;
	
	char c1 ='y' , c2 ='y'  ;
	
	int choice1 , choice2 , price , quantity ;
	string item ;
	
	while(c1 == 'y')
	{
		cout<<"\n---------------Select Operation----------------\n";
		cout<<"\n\t1.Simple Queue using array \n\t2.Simple Queue using Linked List \n\t3.Circular queue using array \n\t4.Circular queue using Linked List\n";
		cout<<"------------------------------------------------\n";
		cout<<"\nenter your choice : ";
		cin>>choice2 ;
		
		switch(choice2)
		{	
			case 1 :				
				c2 ='y' ;
				while(c2 == 'y')
				{	
					cout<<"\n\t1.Enqueue \n\t2.Dequeue \n\t3.Display Food List \n";
					cout<<"\nenter your choice : ";
					cin>>choice1 ;
					
					switch(choice1)
					{						
						case 1 : 
							cout<<"\nEnter item name : ";
							cin>>item ;
							cout<<"\nEnter price : ";
							cin>>price ;
							cout<<"\nEnter Quantity : ";
							cin>>quantity ;
							obj1.enqueue(item , price , quantity);
							break;
							
						case 2 :
							obj1.dequeue();
							break;
							
						case 3 :
							cout<<"\n****** Food List *****\n" ;
							obj1.display() ;
							break;
							
						case 4 :
							cout<<"\ninvalid \n" ;
							break;
					}
					cout<<"\n press y to continue : ";
					cin>>c2 ;
				}
				break ;
				
			case 2 :	
				c2 ='y' ;
				while(c2 == 'y')
				{	
					cout<<"\n\t1.Enqueue \n\t2.Dequeue \n\t3.Display Food List \n";
					cout<<"\nenter your choice : ";
					cin>>choice1 ;
					
					switch(choice1)
					{
						case 1 : 
							cout<<"\nEnter item name : ";
							cin>>item ;
							cout<<"\nEnter price : ";
							cin>>price ;
							cout<<"\nEnter Quantity : ";
							cin>>quantity ;
							obj2.enqueue(item , price , quantity);
							break;
							
						case 2 :
							obj2.dequeue();
							break;
							
						case 3 :
							cout<<"\n ****** Food List ******\n\n" ;
							obj2.display() ;
							break;
							
						case 4 :
							cout<<"\ninvalid \n" ;
							break;	
					}
					cout<<"\npress y to continue : ";
					cin>>c2 ;
				}
				break ;
			
			case 3 :
				c2 ='y' ;
				while(c2 == 'y')
				{	
					cout<<"\n\t1.Enqueue \n\t2.Dequeue \n\t3.Display Food List \n";
					cout<<"\nenter your choice : ";
					cin>>choice1 ;
					
					switch(choice1)
					{	
						case 1 : 
							cout<<"\nEnter item name : ";
							cin>>item ;
							cout<<"\nEnter price : ";
							cin>>price ;
							cout<<"\nEnter Quantity : ";
							cin>>quantity ;
							obj3.enqueue(item , price , quantity);
							break;
							
						case 2 :
							obj3.dequeue();
							break;
							
						case 3 :
							cout<<"\n****** Food List ******\n" ;
							obj3.display() ;
							break;
							
						case 4 :
							cout<<"\ninvalid \n" ;
							break;	
					}
					cout<<"\npress y to continue : ";
					cin>>c2 ;
				}
				break ;
				
			case 4 :
				c2 ='y' ;
				while(c2 == 'y')
				{					
					cout<<"\n\t1.Enqueue \n\t2.Dequeue \n\t3.Display Food List \n";
					cout<<"\nenter your choice : ";
					cin>>choice1 ;
					
					switch(choice1)
					{						
						case 1 : 
							cout<<"\nEnter item name : ";
							cin>>item ;
							cout<<"\nEnter price : ";
							cin>>price ;
							cout<<"\nEnter Quantity : ";
							cin>>quantity ;
							obj4.enqueue(item , price , quantity);
							break;
							
						case 2 :
							obj4.dequeue();
							break;
							
						case 3 :
							cout<<"\n******* Food List ******\n" ;
							obj4.display() ;
							break;
							
						case 4 :
							cout<<"\ninvalid \n" ;
							break;						
					}					
					cout<<"\npress y to continue : ";
					cin>>c2 ;
				}				
				break ;
				
			case 5 :
				cout<<"\ninvalid Choice \n" ;
				break ;		
		}
		cout<<"\npress y to try with other method \n" ;
		cin>>c1 ;
	}	
}

/*
	
        	OUTPUT 

---------------Select Operation----------------

        1.Simple Queue using array
        2.Simple Queue using Linked List
        3.Circular queue using array
        4.Circular queue using Linked List
------------------------------------------------

enter your choice : 1

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : a

Enter price : 20

Enter Quantity : 3

 press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : b

Enter price : 30

Enter Quantity : 2

 press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

****** Food List *****
a       20 Rs * 3
b       30 Rs * 2

 press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 2

Dequeued item is : a
 press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

****** Food List *****
b       30 Rs * 2

 press y to continue : n

press y to try with other method 
y

---------------Select Operation----------------

        1.Simple Queue using array
        2.Simple Queue using Linked List
        3.Circular queue using array
        4.Circular queue using Linked List
------------------------------------------------

enter your choice : 2

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : aa

Enter price : 10

Enter Quantity : 5

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : bb

Enter price : 30

Enter Quantity : 4

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

 ****** Food List ******

aa      10Rs * 5
bb      30Rs * 4

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 2

Dequeud item is : aa
press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

 ****** Food List ******

bb      30Rs * 4

press y to continue : n

press y to try with other method
y

---------------Select Operation----------------

        1.Simple Queue using array
        2.Simple Queue using Linked List
        3.Circular queue using array
        4.Circular queue using Linked List
------------------------------------------------

enter your choice : 3

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

****** Food List ******
 Empty

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : aaa

Enter price : 80

Enter Quantity : 3

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

****** Food List ******
aaa     80Rs * 3

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 2

Dequeued item is : aaa
press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

****** Food List ******
 Empty

press y to continue : n

press y to try with other method
y

---------------Select Operation----------------

        1.Simple Queue using array
        2.Simple Queue using Linked List
        3.Circular queue using array
        4.Circular queue using Linked List
------------------------------------------------

enter your choice : 4

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : aaaa

Enter price : 90

Enter Quantity : 1

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : bbbb

Enter price : 70

Enter Quantity : 2

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 1

Enter item name : cccc

Enter price : 50

Enter Quantity : 3

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

******* Food List ******
aaaa    90Rs * 1
bbbb    70Rs * 2
cccc    50Rs * 3

press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 2

Dequeud element is : aaaa
press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 2

Dequeud element is : bbbb
press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 2

Dequeud item is : cccc
press y to continue : y

        1.Enqueue
        2.Dequeue
        3.Display Food List

enter your choice : 3

******* Food List ******
 Empty

press y to continue : n

press y to try with other method

n

--------------------------------
Process exited after 280.9 seconds with return value 0
Press any key to continue . . .

*/
