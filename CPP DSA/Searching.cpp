/*
		name = harshwardhan tilekar
		roll no = 23
		title = Design and implement a menu driven program for 
				implementing Fibonacci, binary and sentinel
				searching for students marks scored in an examination.
*/


#include<iostream>
using namespace std  ;
#define max 4 

class students{
	
	public :
		int marks , roll_no ;
		string name ;	
};

class search
{	
	public : 
		students arr[max] ;	
		int n ;
		
		void getdata() ;
		void showData( int size);
		int fibonacci_search(int n, int x) ; // Fibonacci Search
		int binary_search(int lb, int ub, int x) ; //Binary Search
		int sentinel_search( int n, int info) ; //Sentinel Search
		void sort( int n) ;	// Sorting	
};

void search :: getdata(){
	
	for(int i=0;i<max;i++){
		
			cout<<"\nenter Name : ";
			cin>>arr[i].name;
			
			cout<<"enter Roll Number : ";
			cin>>arr[i].roll_no ;
			
			cout<<"enter Marks  : ";
			cin>>arr[i].marks;
			
	}
	
}

void search::showData(int size)
{
	int i;
	cout<<"\n\t\tName \t Roll_No \t Marks\n" ;
	for (i=0; i < size; i++)
		cout<<"\t\t"<<arr[i].name<<"\t\t"<<arr[i].roll_no<<"\t\t"<<arr[i].marks<<endl ;
}

void search :: sort(int n){
	int i , j  ;
	students info ;
	
	for (j = 1; j < n; j++)
	{
		info = arr[j] ;
		
		i = j - 1;

		while (i >= 0 && arr[i].marks > info.marks)
		{
			arr[i + 1] = arr[i]; 
			i-- ;
		}
		
		arr[i + 1] = info ;
	}
	
}

int search :: fibonacci_search( int n, int x){
	
	int f2 = 0; 
	int f1 = 1;
	int fib= f2 + f1; 
	while (fib < n)
	{ 
 		f2 = f1; 
 		f1 = fib; 
 		fib = f2 + f1; 
 	} 
	
	int offset = -1; 
	while (fib > 1)
	{ 
	int i = min(offset+f2, n-1);  if (arr[i].marks < x)
	{ 
 		fib=f1; 
 		f1=f2; 
 		f2 =fib-f1; 
 		offset=i; 
 	} 
 	else if (arr[i].marks > x)
	{  
		fib=f2; 
		f1=f1-f2; 
 	    f2=fib-f1; 
    } 
 	
	else 
    	return i; 
    } 
	if(f1 && arr[offset+1].marks==x)  
		return offset+1; 
 
    else 
    	return -1;
}

int search :: binary_search( int lb, int ub, int x){
	
	if (ub >= lb) {
        int mid = lb + (ub - lb) / 2;
 
        if (arr[mid].marks == x)
            return mid;
 
        if (arr[mid].marks > x)
            return binary_search(lb, mid - 1, x);
 		
 		else
        	return binary_search( mid + 1, ub, x);
    }
 
    return -1;
}

int search :: sentinel_search( int n, int info){
	
	int last = arr[n - 1].marks;
 
    arr[n - 1].marks = info;
    int i = 0;
 
    while (arr[i].marks != info)
        i++;
 
    arr[n - 1].marks = last;
 
    if ((i < n - 1) || (arr[n - 1].marks == info))
        return i ;
    else
        return -1 ;
}

int main(){
	
	search s ;
	char c = 'y' ;
	int choice , info , result ;
	
	while(c == 'y'){
		
		cout<<"\n------------ operations for searching -----------\n";
		cout<<"\n\t\t1. Fibonacci Search\n\t\t2. Binary Search\n\t\t3. Sentinel Search\n\n";
		cout<<"\t------------------------------------\n";
		
		cout<<"enter your choice : ";
		cin>>choice ;
		
		switch(choice){
			
			case 1 :
				s.getdata() ;
				
				cout<<"\nEnter marks for search operation : " ;
				cin>>info ;
				
				s.sort(max) ;
				s.showData( max) ;
				
				result = s.fibonacci_search(max , info ) ;
				
				if(result == -1)
					cout << "\nStudent with given marks is not present" ;
				else 
					cout << "\n\tStudent with given marks at index " << result;
					
				break ;
				
				
			case 2 :
				s.getdata() ;
				
				cout<<"\nEnter marks for search operation : " ;
				cin>>info ;
				
				s.sort(max);
				s.showData(max) ;
				result = s.binary_search(0 , max-1 , info ) ;
				
				if(result == -1)
					cout << "\nStudent with given marks is not present" ;
				else 
					cout << "\n\tStudent with given marks at index " << result;
					
				break ;
			
			case 3 :
				
				s.getdata() ;
				
				cout<<"\nEnter marks for search operation : " ;
				cin>>info ;
				
				s.sort(max);
				s.showData(max) ;
				result = s.sentinel_search( max , info ) ;
				
				if(result == -1)
					cout << "\nStudent with given marks is not present" ;
				else 
					cout << "\n\tStudent with given marks at index " << result;
				
				break ;
					
			default :
				cout<<"\ninvalid\n" ;
				
				break ;
		}
		
		cout<<"\npress y to continue ";
		cin>>c ;
	}
	 	
	return 0 ;
}


	
/*
						OUTPUT 
	
	
		------------ operations for searching -----------
		
		                1. Fibonacci Search
		                2. Binary Search
		                3. Sentinel Search
		
		        ------------------------------------
		enter your choice : 1
		
		enter Name : a
		enter Roll Number : 534
		enter Marks  : 54
		
		enter Name : s
		enter Roll Number : 5663
		enter Marks  : 564
		
		enter Name : d
		enter Roll Number : 35
		enter Marks  : 53
		
		enter Name : f
		enter Roll Number : 3658
		enter Marks  : 356
		
		Enter marks for search operation : 54
		
		                Name     Roll_No         Marks
		                d               35              53
		                a               534             54
		                f               3658            356
		                s               5663            564
		
		        Student with given marks at index 1
		press y to continue y
		
		------------ operations for searching -----------
		
		                1. Fibonacci Search
		                2. Binary Search
		                3. Sentinel Search
		
		        ------------------------------------
		enter your choice : 2
		
		enter Name : g
		enter Roll Number : 4
		enter Marks  : 8
		
		enter Name : h
		enter Roll Number : 9
		enter Marks  : 6
		
		enter Name : j
		enter Roll Number : 7
		enter Marks  : 5
		
		enter Name : j
		enter Roll Number : 87
		enter Marks  : 56
		
		Enter marks for search operation : 5
		
		                Name     Roll_No         Marks
		                j               7               5
		                h               9               6
		                g               4               8
		                j               87              56
		
		        Student with given marks at index 0
		press y to continue y
		
		------------ operations for searching -----------
		
		                1. Fibonacci Search
		                2. Binary Search
		                3. Sentinel Search
		
		        ------------------------------------
		enter your choice : 3
		
		enter Name : w
		enter Roll Number : 652
		enter Marks  : 62
		
		enter Name : e
		enter Roll Number : 62
		enter Marks  : 26
		
		enter Name : r
		enter Roll Number : 87
		enter Marks  : 54
		
		enter Name : t89
		enter Roll Number : 56
		enter Marks  : 56
		
		Enter marks for search operation : 30
		
		                Name     Roll_No         Marks
		                e               62              26
		                r               87              54
		                t89             56              56
		                w               652             62
		
		Student with given marks is not present
		press y to continue n
		
		--------------------------------
		Process exited after 107 seconds with return value 0
		Press any key to continue . . .




*/
