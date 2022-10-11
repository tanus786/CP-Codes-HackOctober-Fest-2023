#include<iostream>
#include<math.h>
using namespace std;

class Heap
{
	public:
		int n;
		int arr[100];
		void getarray();
		void print();
		void maxheapsort(int arr[],int n);
		void minheapsort(int arr[],int n);
		void maxheapify(int arr[],int i,int n);
		void minheapify(int arr[],int i,int n);
		
};


void Heap :: getarray()
{
	cout<<"\nEnter number of elements: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
}


void Heap :: print()
{
    cout<<"\nArray is as follows: \n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}


void Heap :: maxheapify(int arr[],int i,int n)
{
	int max=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n and arr[left]>arr[max])
	{
		max=left;
	}
	
	if(right<n and arr[right]>arr[max])
	{
		max=right;
	}
	
	if(max!=i)
	{
		swap(arr[i],arr[max]);
		maxheapify(arr,max,n);
	}
	
}


void Heap :: minheapify(int arr[],int i,int n)
{
	int min=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n and arr[left]<arr[min])
	{
		min=left;
	}
	
	if(right<n and arr[right]<arr[min])
	{
		min=right;
	}
	
	if(min!=i)
	{
		swap(arr[i],arr[min]);
		minheapify(arr,min,n);
	}
	
}

void Heap::maxheapsort(int arr[],int n) //ascending
{ 
    for(int i=((n/2)-1); i>= 0; i--) 
    { 
        maxheapify(arr,i,n); 
    }
	 
    for(int i = n - 1; i >= 0; i--) 
    { 
        swap(arr[0], arr[i]); 
        maxheapify(arr,0,i); 
    } 
 
}


void Heap::minheapsort(int arr[],int n)//descending 
{ 
    for(int i=((n/2)-1); i>= 0; i--) 
    { 
        minheapify(arr,i,n); 
    }
	 
    for(int i = n - 1; i >= 0; i--) 
    { 
        swap(arr[0], arr[i]); 
        minheapify(arr,0,i); 
    } 
 
}


int main()
{
	int ch,a='y';
	Heap h;
	
	cout<<"\n----------------Heap Sort-----------------\n\n";
	
    h.getarray();
    cout<<"\n--------------------------------------\n\n";
    h.print();
    cout<<"\n--------------------------------------\n\n";
    cout<<"\n\nSorted array (maxheapify)\n";
    h.maxheapsort(h.arr,h.n);
    h.print();
    
    cout<<"\n--------------------------------------\n\n";
    cout<<"\n\nSorted array (minheapify)\n";
    h.minheapsort(h.arr,h.n);
    h.print();
	
	return 0;
}


