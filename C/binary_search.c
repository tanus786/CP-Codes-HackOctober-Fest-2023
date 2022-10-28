#include<stdio.h>
#include<stdlib.h>

void display(int a[],int size)
{ int i;
  printf("The given array is\n");
  for(i=0;i<size;i++)
  printf("%d ",a[i]);
  
  printf("\n");
  
}

int bSearch(int key,int a[],int size)
{
	int front=0,rear=size-1,mid;
	
	while(front!=rear)
	{   
		mid=(front+rear)/2;
		
		if(key==a[mid])
		{   printf("%d ",mid);
		    return mid;
		}
		else if(key<a[mid])
		{
			rear=mid;
		}		
		else if(key>a[mid])
		{ 
		  front=mid+1;
		}

	}
	printf("Element not found\n");
}

int main()
{ int size,i,key;
  printf("Enter the size of the array\n");
  scanf("%d",&size);
  int a[size];
  printf("Enter the elements of the array\n");
  for(i=0;i<size;i++)
  scanf("%d",&a[i]);
  display(a,size);
  printf("Enter the element you want to search\n");
  scanf("%d",&key);
  bSearch(key,a,size);
  
  return 0;

  	
}
