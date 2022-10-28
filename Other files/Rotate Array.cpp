#include<iostream>
using namespace std;


void leftRotateByD(int *arr,int n,int d)
{
  
  int temp[d];
  for (int i=0;i<d;i++)
  {
    temp[i]=arr[i];
  }
  
  
  int x=0;
  for(int j=d;j<n;j++)
  {
    arr[x]=arr[j];
    x++;
  }
  
  
  x=0;
  for (int k=n-d;k<n;k++)
  {
    arr[k]=temp[x];
    x++;
  }
  
}
  

int main()
{
  int n,d;
  
  cout<<"Enter the size of array\n";
  cin>>n;
  
  int arr[n];
  cout<<"Enter the elements of array\n";
  for (int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  
  cout<<"Enter the value of D\n";
  cin>>d;
  
  /* function call to rotate the array */
  leftRotateByD(arr,n,d); 
    
  cout<<"Array after left rotation by D places\n";
  for (int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  
  
  return 0;
}
