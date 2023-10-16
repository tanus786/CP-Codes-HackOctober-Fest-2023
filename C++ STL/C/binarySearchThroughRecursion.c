#include<conio.h>
#include<stdio.h>

int binary(int A[],int low,int high,int item)
{
    int mid;
    if(high>=low)
    {
        mid = (low+high)/2;
        if(A[mid] == item)
        {
            return mid;
            
        }
        if(A[mid]>item)
            return binary(A,low,mid-1,item);
        else 
            return binary(A,mid+1,high,item);
    }
    return -1;

}
int main()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};
    int value = 5,index;
    int n=10;
    index = binary(A,0,n-1,value);
    if(index == -1)
    {
        printf("\n number not found ");
    }
    else
    {
        printf("\n %d Found at %d ",value,index);
    }
    
}
