/*
	name = harshwardhan tilekar
	roll no = 23
	title = Design and implement a program for double 
			ended queue and its operations for a shopping mall.
*/


#include<iostream>
using namespace std;
#define max 5


class shopping_mall
{
	public:	
		string item;
		int quantity,price;
		
		void getdata()
		{
			cout<<"\nEnter the name : ";
		    cin>>item;
		    cout<<"Enter the quantity : ";
			cin>>quantity;
			cout<<"Enter the price : ";
			cin>>price;	
		}
};

class dequeue
{	
	public:		
		shopping_mall data[max];
		int front,rear;
		
		dequeue()
		{
			rear =-1;
			front =-1;
		}
		
		bool isFull();
		bool isEmpty();
		void insert_front(shopping_mall s);
		void insert_rear(shopping_mall s);
		void delete_front();
		void delete_rear();
		void display();
	
};

bool dequeue::isFull()
{
	if((front==0 && rear==max-1) || (front==rear+1))
		return true;
	else
		return false;
}

bool dequeue::isEmpty()
{
	if(front==-1)
		return true;
	else
		return  false;
}

void dequeue::insert_front(shopping_mall s)
{
	if(isFull())
	{
		cout<<"dequeue is full"<<endl ;
	}
	else
	{
		 if(isEmpty())
		{
			front = 0;
			rear =0;
		}
		else
		{
			front=(front-1+max)%max;
		}
		data[front].item = s.item;
		data[front].quantity =s.quantity;
		data[front].price =s.price;
	}
}

void dequeue::insert_rear(shopping_mall s)
{	
	if(isFull())
	{
		cout<<"\n Dequeue is full \n"<<endl;
	}
	else if(front==-1)
	{
		front =0;
		rear=0;
	}
	else 
	{
		rear=(rear+1)%max;
	}
		data[rear].item = s.item;
		data[rear].quantity =s.quantity;
		data[rear].price =s.price;	
}

void dequeue::delete_front()
{
	if(isEmpty())
	{
		cout<<"\ndequeue is empty"<<endl;
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front=(front+1+max)%max;
	}	
}

void dequeue::delete_rear()
{
	if(isEmpty())
	{
		cout<<"\ndequeue is empty"<<endl;
	}
	else if(front==rear)
	{ 
		front=-1;
		rear=-1;
	}
	else
	{
		rear=(rear-1+max)%max;
	}	
}

void dequeue::display()
{
	int i=front;
	
	cout<<"\n\t----------operations for a shopping mall-----------\n";
	cout<<"\n\t-----------------------------------------------------\n";

	
	cout<<"\n **** Shopping details **** \n\n" ;
	
	if(isEmpty())
	{
		cout<<"\ndequeue is empty\n"<<endl;
	}
	else if(front<=rear)
	{
		for(int i =front; i<=rear;i++)
		{
			cout<<"\n\t-----------------------------";
			cout<<"\n\t\tItem     : "<<data[i].item ;
			cout<<"\n\t\tQuantity : "<<data[i].quantity ;
			cout<<"\n\t\tPrice    : "<<data[i].price<<"" ;
			cout<<"\n\t-----------------------------\n";
		}
	}
	else
	{
		while(i<=max-1)
		{
			cout<<"\n\t-----------------------------";
			cout<<"\n\t\tItem     : "<<data[i].item ;
			cout<<"\n\t\tQuantity : "<<data[i].quantity ;
			cout<<"\n\t\tPrice    : "<<data[i].price<<"" ;
			cout<<"\n\t-----------------------------\n";
			
			i++;
		}
		i=0;
		while(i<=rear)
		{
			cout<<"\n\t-----------------------------";
			cout<<"\n\t\tItem     : "<<data[i].item ;
			cout<<"\n\t\tQuantity : "<<data[i].quantity ;
			cout<<"\n\t\tPrice    : "<<data[i].price<<"" ;
			cout<<"\n\t-----------------------------\n";
			
			i++;
		}
	}
}


int main()
{
	shopping_mall sm;
	dequeue d;
	
	int c;
	do 
	{
		cout<<"\n\n\n\t----------operations for a shopping mall-----------\n";
		cout<<"\n\t\t\t1.insert at front \n\t\t\t2.insert at rear \n\t\t\t3.display";
		cout<<"\n\t\t\t4.delete from front \n\t\t\t5.delete from rear \n\t\t\t6.exit\n";
		cout<<"\n\t-----------------------------------------------------\n";

        cout<<"\n\nEnter your choice : ";
        cin>>c;
       
	   	switch(c)
	   	{
		  	case 1 :
		  		sm.getdata();
		  		d.insert_front(sm);
		  		break;
		  		
		  	case 2 :
			  	sm.getdata();
				d.insert_rear(sm);
				break;
				  
			case 3 : 
				d.display();
				break;
				
			case 4 : 
				d.delete_front();
				break;
				
			case 5 :
				d.delete_rear();
				break;
				
			case 6 :
				break;
				
			default : cout<<"\ninvalid choice\n"<<endl;				  	
	   	} 
	} 
	while(c!=6) ;
	return 0 ;
}


/*

				OUTPUT 
				



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 1

Enter the name : shirt
Enter the quantity : 2
Enter the price : 300



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 1

Enter the name : pant
Enter the quantity : 2
Enter the price : 1000



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 3

        ----------operations for a shopping mall-----------

        -----------------------------------------------------

 **** Shopping details ****


        -----------------------------
                Item     : pant
                Quantity : 2
                Price    : 1000
        -----------------------------

        -----------------------------
                Item     : shirt
                Quantity : 2
                Price    : 300
        -----------------------------



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 2

Enter the name : shoes
Enter the quantity : 5
Enter the price : 600



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 2

Enter the name : socks
Enter the quantity : 1
Enter the price : 50



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 3

        ----------operations for a shopping mall-----------

        -----------------------------------------------------

 **** Shopping details ****


        -----------------------------
                Item     : pant
                Quantity : 2
                Price    : 1000
        -----------------------------

        -----------------------------
                Item     : shirt
                Quantity : 2
                Price    : 300
        -----------------------------

        -----------------------------
                Item     : shoes
                Quantity : 5
                Price    : 600
        -----------------------------

        -----------------------------
                Item     : socks
                Quantity : 1
                Price    : 50
        -----------------------------



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 4



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 3

        ----------operations for a shopping mall-----------

        -----------------------------------------------------

 **** Shopping details ****


        -----------------------------
                Item     : shirt
                Quantity : 2
                Price    : 300
        -----------------------------

        -----------------------------
                Item     : shoes
                Quantity : 5
                Price    : 600
        -----------------------------

        -----------------------------
                Item     : socks
                Quantity : 1
                Price    : 50
        -----------------------------



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 5



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 3

        ----------operations for a shopping mall-----------

        -----------------------------------------------------

 **** Shopping details ****


        -----------------------------
                Item     : shirt
                Quantity : 2
                Price    : 300
        -----------------------------

        -----------------------------
                Item     : shoes
                Quantity : 5
                Price    : 600
        -----------------------------



        ----------operations for a shopping mall-----------

                        1.insert at front
                        2.insert at rear
                        3.display
                        4.delete from front
                        5.delete from rear
                        6.exit

        -----------------------------------------------------


Enter your choice : 6

--------------------------------
Process exited after 85.44 seconds with return value 0
Press any key to continue . . .
				
*/
