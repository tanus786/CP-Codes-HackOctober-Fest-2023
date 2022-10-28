/*

name = harshwardhan tilekar
roll no = 23
title = Design and develop program for polynomial addition, multiplication operations for disease information using circular linked list.

*/

#include<iostream>
using namespace std;
class node
{
    public:
    int data,coef,expo;
    node *next;
};
class poly
{
    public:
    node*head; 
    int len;
    poly()
	{
        head=NULL;
        len=0;
    }
    void sorted_create(node *temp);
    void add(poly p1,poly p2);
    void multiply(poly p1,poly p2);
    void display();

};

void poly :: sorted_create(node *temp)                                // ********  CREATE ******** //
{
	node*p;

    if(head==NULL)
	{
        head=temp;
	}
    else
	{
		if(temp->expo > head->expo)
		{
        	temp->next=head;
        	p=head;
        	
            while(p->next!=head)
			{
                p=p->next;
            }
            p->next=temp;
            head=temp;
        }
        else
        {
        	if(temp->expo == head->expo)
        	{
        		head->coef+=temp->coef;
			}
			else
			{
				p=head;
				int f=0;
	            while(1)
				{
					if(p->expo == temp->expo)
		        	{
		        		p->coef+=temp->coef;
		        		f=2;
		        		break;
					}
					else if((p->expo > temp->expo && 
							p->next->expo < temp->expo)
							||(p->next==head))
					{
						f=1;
						break;	
					}
					p=p->next;
	            }
	            if(f==1)
	            {
	            	temp->next=p->next;
	            	p->next=temp;
				}
	    	}
		}
	}
}



void poly :: add(poly p1,poly p2)                  		 // ********  ADDITION  ******** //
{
	node *t1,*t2,*t3;
	t1=p1.head;
	t2=p2.head;
	if(t1==NULL && t2==NULL)
	{
		cout<<"both are null";
		return;
	}
	do
	{
		t3=new node;
		t3->coef=t1->coef;
		t3->expo=t1->expo;
		t3->next=t3;
		
		sorted_create(t3);
		t1=t1->next;
	}
	while(t1!=p1.head);
	
	do
	{
		t3=new node;
		t3->coef=t2->coef;
		t3->expo=t2->expo;
		t3->next=t3;
		
		sorted_create(t3);
		t2=t2->next;
	}
	while(t2!=p2.head);	
}

void poly :: multiply(poly p1,poly p2)               		   // ********  MULTIPLICATION  ******** //
{
	node *t1,*t2,*t3;
	t1=p1.head;
	t2=p2.head;
	if(t1==NULL && t2==NULL)
	{
		cout<<"both are null";
		return;
	}
	do
	{
		t2=p2.head;
		do
		{
			t3=new node;
			t3->coef=t1->coef*t2->coef;
			t3->expo=t1->expo+t2->expo;
			t3->next=t3;
			
			sorted_create(t3);
			t2=t2->next;
		}
		while(t2!=p2.head);
		t1=t1->next;
	}
	while(t1!=p1.head);
}


void poly :: display()                                     		 // ********  DISPLAY ******** //
{
    node *p = head;
    cout<<"\n\t polynomial is  ";
	cout<<"\n\t\t\t ";
    while(p->next!=head)
	{
		cout<<p->coef<<"x^"<<p->expo<<" + ";
        p=p->next;
    }
    cout<<p->coef<<"x^"<<p->expo<<" = 0"<<endl;
}
  
int main()
{
    poly p1,p2,p3,p4;
    int choice;
    char ch2;
    
    node*t;
	cout<<"\n#####  polynomial 1  ######\n"<<endl;
	cout<<"***enter - (minus) sign if applicable ***\n"<<endl;
	char ch;
	do
	{
		t=new node;
		int val;
		cout<<"\t\t\t------------------------------------";
		cout<<"\n\t\t\t|\t enter coefficient  = ";
		cin>>t->coef;
		cout<<"\t\t\t|\t enter exponent  = ";
		cin>>t->expo;
		cout<<"\t\t\t------------------------------------";
		
		t->next=t;
		
		p1.sorted_create(t);
		
        cout<<"\n\nwanna add more data (y/n) : ";
        cin>>ch;

	}
	while(ch == 'y');
	
	p1.display();
	

	node*t1;
	cout<<"\n\n######  polynomial 2  #####\n"<<endl;
	cout<<"***enter - (minus) sign if applicable ***\n"<<endl;
	char ch1;
	do
	{
		t1=new node;
		int val;
			cout<<"\t\t\t------------------------------------";
		cout<<"\n\t\t\t|\t enter coefficient  = ";
		cin>>t1->coef;
		cout<<"\t\t\t|\t enter exponent  = ";
		cin>>t1->expo;
		cout<<"\t\t\t------------------------------------";
		t1->next=t1;
		
		p2.sorted_create(t1);
		
        cout<<"\nwanna add more data (y/n) : ";
        cin>>ch1;

	}while(ch1 == 'y');
	
	p2.display();
	
	
	do
	{	
	
		cout<<"\n\t\t########  MENU  #########";
		cout<<"\n\t\t1)addition \n\t\t2)multiplication "<<endl;
		cout<<"\nenter your choice : ";
		cin>>choice;
	
		switch (choice)	
		{
			case 1:
				cout<<"\nafter addition : ";
				p3.add(p1,p2);
				p3.display();
				break;
				
			case 2:
				cout<<"\nafter multiplication : ";
				p4.multiply(p1,p2);
				p4.display();
				break;
				
			default:
				cout<<"\n invalid choice -_-";			
		}
		cout<<"\n enter y to continue (y/n): ";
		cin>>ch2	;
	}
	while(ch2=='y');	
}




/*                            // ********  output ******** //


#####  polynomial 1  ######

***enter - (minus) sign if applicable ***

                        ------------------------------------
                        |        enter coefficient  = 1
                        |        enter exponent  = 2
                        ------------------------------------

wanna add more data (y/n) : y
                        ------------------------------------
                        |        enter coefficient  = 2
                        |        enter exponent  = 3
                        ------------------------------------

wanna add more data (y/n) : y
                        ------------------------------------
                        |        enter coefficient  = 3
                        |        enter exponent  = 4
                        ------------------------------------

wanna add more data (y/n) : y
                        ------------------------------------
                        |        enter coefficient  = 4
                        |        enter exponent  = 5
                        ------------------------------------

wanna add more data (y/n) : n

         polynomial is
                         4x^5 + 3x^4 + 2x^3 + 1x^2 = 0


######  polynomial 2  #####

***enter - (minus) sign if applicable ***

                        ------------------------------------
                        |        enter coefficient  = 1
                        |        enter exponent  = 0
                        ------------------------------------
wanna add more data (y/n) : y
                        ------------------------------------
                        |        enter coefficient  = 2
                        |        enter exponent  = 6
                        ------------------------------------
wanna add more data (y/n) : y
                        ------------------------------------
                        |        enter coefficient  = 9
                        |        enter exponent  = 3
                        ------------------------------------
wanna add more data (y/n) : y
                        ------------------------------------
                        |        enter coefficient  = 11
                        |        enter exponent  = 1
                        ------------------------------------
wanna add more data (y/n) : n

         polynomial is
                         2x^6 + 9x^3 + 11x^1 + 1x^0 = 0

                ########  MENU  #########
                1)addition
                2)multiplication

enter your choice : 1

after addition :
         polynomial is
                         2x^6 + 4x^5 + 3x^4 + 11x^3 + 1x^2 + 11x^1 + 1x^0 = 0

 enter y to continue (y/n): y

                ########  MENU  #########
                1)addition
                2)multiplication

enter your choice : 2

after multiplication :
         polynomial is
                         8x^11 + 6x^10 + 4x^9 + 38x^8 + 27x^7 + 62x^6 + 46x^5 + 25x^4 + 13x^3 + 1x^2 = 0

 enter y to continue (y/n): n

--------------------------------
Process exited after 133.1 seconds with return value 0
Press any key to continue . . .

*/
