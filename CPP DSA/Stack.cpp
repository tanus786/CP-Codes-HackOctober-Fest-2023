/*
		name = harshwardhan tilekar
		roll no = 23
		title = Design and develop a program using linear recurrence
				relations for various loan schemes of a bank.
*/


#include<iostream>
using namespace std;

float return_amount(float amount  , float interest , float time)
{	
	if( time == 0)
	{
		return amount ;
	}
	
	amount = (interest/100)*amount + amount ;
		
	return return_amount(amount,interest,time-1) ; //recursion	
}

int main()
{
	int time,choice,amount;
	float interest;
	char c='y';

	while(c=='y')
	
	{
		cout<<"\n**--**--**-- bank of pune --**--**--**\n";	
		cout<<"\n\t------------ loan schemes -----------";
		cout<<"\n\t\t1. Education Loan\n\t\t2. Car loan\n\t\t3. Gold loan\n";
		cout<<"\t------------------------------------\n\n";
		
		cout<<"enter your choice : ";
		cin>>choice ;
		
		switch(choice)
		{
			case 1:
				cout<<"\n\t---- Education Loan ----\n"<<endl;

				cout<<"\tRs. 50,000 to Rs. 300000 ,  interest rate 8 %"<<endl;
				cout<<"\tRs. 300000 to Rs. 6,00,000  ,  interest rate 10 %"<<endl;
				
				cout<<"\nEnter the amount you want :";
				cin>>amount;
				
				cout<<"\nEnter the time : ";
				cin>>time;

				if(amount>50000 && amount<=300000)
				{
					interest=8;
				}
				else if(amount>300000 && amount<=600000)
				{
					interest=10;
				}
				else
				{
					cout<<"\ninvalid\n ";
					break;
				}
					
				cout<<"\nTotal payment to pay after "<<time<<" years is "<<return_amount(amount,interest,time);
				break;
				
				
			case 2:
				cout<<"\n---- Car Loan ----\n"<<endl;
				
				cout<<"\tRs. 100000 to Rs. 500000 ,  interest rate 10 %"<<endl;
				cout<<"\tRs. 500000 to Rs. 1000000  ,  interest rate 12 %"<<endl;
				
				cout<<"\nEnter the amount you want :";
				cin>>amount;
				
				cout<<"\nEnter the time : ";
				cin>>time;
				
 
				if(amount>100000 && amount<=500000)
				{
					interest=10;
				}
				else if(amount>500000 && amount<=1000000)
				{
					interest=12;
				}
				else
				{
					cout<<"\ninvalid\n ";
					break;
				}
					
				cout<<"\nTotal payment to pay after "<<time<<" years is "<<return_amount(amount,interest,time);
				break;	
				
			case 3:
				cout<<"\n---- Gold Loan ----\n"<<endl;
				
				cout<<"\tRs. 30000 to Rs. 100000 ,  interest rate 6 %"<<endl;
				cout<<"\tRs. 100000 to Rs. 500000  ,  interest rate 8 %"<<endl;
				
				cout<<"\nEnter the amount you want :";
				cin>>amount;
				
				cout<<"\nEnter the time : ";
				cin>>time;
				
 
				if(amount>30000 && amount<=100000)
				{
					interest=6;
				}
				else if(amount>100000 && amount<=500000)
				{
					interest=8;
				}
				else
				{
					cout<<"\ninvalid\n ";
					break;
				}
					
				cout<<"\nTotal payment to pay after "<<time<<" years is "<<return_amount(amount,interest,time);
				break;
				
			default:
				cout<<"\ninvalid";
				break;
		}
		
		cout<<"\n\npress y to continue :  ";
		cin>>c;
	}
}

/*
				OUTPUT 
	
	
**--**--**-- bank of pune --**--**--**

        ------------ loan schemes -----------
                1. Education Loan
                2. Car loan
                3. Gold loan
        ------------------------------------

	enter your choice : 1
	
	        ---- Education Loan ----
	
	        Rs. 50,000 to Rs. 300000 ,  interest rate 8 %
	        Rs. 300000 to Rs. 6,00,000  ,  interest rate 10 %
	
	Enter the amount you want :65000
	
	Enter the time : 6
	
	Total payment to pay after 6 years is 103147
	
	press y to continue :  y
	
	**--**--**-- bank of pune --**--**--**
	
	        ------------ loan schemes -----------
	                1. Education Loan
	                2. Car loan
	                3. Gold loan
	        ------------------------------------
	
	enter your choice : 2
	
	---- Car Loan ----
	
	        Rs. 100000 to Rs. 500000 ,  interest rate 10 %
	        Rs. 500000 to Rs. 1000000  ,  interest rate 12 %
	
	Enter the amount you want :650000
	
	Enter the time : 4
	
	Total payment to pay after 4 years is 1.02279e+006
	
	press y to continue :  y
	
	**--**--**-- bank of pune --**--**--**
	
	        ------------ loan schemes -----------
	                1. Education Loan
	                2. Car loan
	                3. Gold loan
	        ------------------------------------
	
	enter your choice : 3
	
	---- Gold Loan ----
	
	        Rs. 30000 to Rs. 100000 ,  interest rate 6 %
	        Rs. 100000 to Rs. 500000  ,  interest rate 8 %
	
	Enter the amount you want :60
	
	Enter the time : 2
	
	invalid
	
	
	press y to continue :  y
	
	**--**--**-- bank of pune --**--**--**
	
	        ------------ loan schemes -----------
	                1. Education Loan
	                2. Car loan
	                3. Gold loan
	        ------------------------------------
	
	enter your choice : 3
	
	---- Gold Loan ----
	
	        Rs. 30000 to Rs. 100000 ,  interest rate 6 %
	        Rs. 100000 to Rs. 500000  ,  interest rate 8 %
	
	Enter the amount you want :123456
	
	Enter the time : 1
	
	Total payment to pay after 1 years is 133332
	
	press y to continue :  n
	
	--------------------------------
	Process exited after 59.16 seconds with return value 0
	Press any key to continue . . .


*/
