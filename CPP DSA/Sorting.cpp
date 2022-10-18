/*
		name = harshwardhan tilekar
		roll no = 23
		title = Design and implement a menu driven program
				for implementing insertion sort and quick sort for
				population of a town
*/


#include<iostream>
using namespace std  ;
#define max 4 

class town
{	
	public :
		int population ;
		string name ;		
};

class sort
{
	public :		
		town arr[max] ; 		
		
		void getdata();  //for input				
		void swap(town* a, town* b) ; //to swap data 				
		int partition (int low, int high) ; // partition around pivot element		
		void quickSort( int low, int high) ; //quick sort		
		void insertion_sort(int n) ; //insertion sort
		void showData(int size) ;//for display
};

void sort::getdata()
{
	for(int i=0;i<max;i++)
	{
			cout<<"\n\tenter Town Name : ";
			cin>>arr[i].name;
			cout<<"\tenter Town Population : ";
			cin>>arr[i].population;
	}
	cout<<"\n\n";
}

void sort::swap(town* a, town* b)
{
	town t = *a;
	*a = *b;
	*b = t;
}


int sort::partition ( int lb, int ub)
{
	int pivot = arr[lb].population , start = lb , end = ub ; 

	while(start < end)
	{
		
		while(arr[start].population <= pivot )
		{
			start ++ ;
		}
		
		while(arr[end].population > pivot )
		{
			end -- ;
		}
		
		if(start < end )
		{	
			swap(&arr[start], &arr[end]);			
		}	
	}	
	swap(&arr[lb], &arr[end]);
	return end ;
}


void sort::quickSort(int lb, int ub)
{
	if (lb < ub)
	{ 
		int location = partition(lb, ub);
		quickSort( lb, location - 1 );
		quickSort( location + 1, ub );
	}
}

void sort::insertion_sort(int n)
{	
	int i , j  ;
	town key ;
	
	for (j = 1; j < n; j++)
	{
		key = arr[j] ;
		i = j - 1;

		while (i >= 0 && arr[i].population > key.population)
		{
			arr[i + 1] = arr[i]; 
			i-- ;
		}
		arr[i + 1] = key ;
	}
}

void sort::showData( int size)
{
	int i;
	cout<<"\t||| Sorted list according to population ||| \n\n" ;
	for (i=0; i < size; i++)
		cout<<"\t\t\t"<<arr[i].name<<" : "<<arr[i].population<<endl ;
}



int main()
{	
	sort s ;
	char c = 'y' ;
	int choice ;
	
	while(c == 'y')
	{	
		cout<<"\n------------ operations for sorting -----------\n";
		cout<<"\n\t\t1. quick sort\n\t\t2. insertion sort\n";
		cout<<"\t------------------------------------\n";
		
		cout<<"\nener your choice : ";
		cin>>choice ;
		
		switch(choice)
		{	
			case 1 :
				s.getdata() ;
				s.quickSort( 0, max-1);
				s.showData(max);
				break ;
				
			case 2 :
				s.getdata() ;
				s.insertion_sort( max) ;
				s.showData( max);
				break ;
				
			default :
				cout<<"\ninvalid \n" ;
				break ;
		}
		
		cout<<"\npress yto continue ";
		cin>>c ;
	}	
	return 0;
}

/*

			--------------OUTPUT-------------- 


		------------ operations for sorting -----------
		
		                1. quick sort
		                2. insertion sort
		        ------------------------------------
		
		ener your choice : 1
		
		        enter Town Name : alandi
		        enter Town Population : 200000
		
		        enter Town Name : pimpri
		        enter Town Population : 894635
		
		        enter Town Name : chikhali
		        enter Town Population : 64115984
		
		        enter Town Name : panvel
		        enter Town Population : 515748515
		
		
		        ||| Sorted list according to population |||
		
		                        alandi : 200000
		                        pimpri : 894635
		                        chikhali : 64115984
		                        panvel : 515748515
		
		press yto continue y
		
		------------ operations for sorting -----------
		
		                1. quick sort
		                2. insertion sort
		        ------------------------------------
		
		ener your choice : 2
		
		        enter Town Name : akluj
		        enter Town Population : 456416
		
		        enter Town Name : swargate
		        enter Town Population : 5465164
		
		        enter Town Name : dehu
		        enter Town Population : 8674561
		
		        enter Town Name : thane
		        enter Town Population : 56465166
		
		
		        ||| Sorted list according to population |||
		
		                        akluj : 456416
		                        swargate : 5465164
		                        dehu : 8674561
		                        thane : 56465166
		
		press yto continue n
		
		--------------------------------
		Process exited after 121.4 seconds with return value 0
		Press any key to continue . . .

*/
