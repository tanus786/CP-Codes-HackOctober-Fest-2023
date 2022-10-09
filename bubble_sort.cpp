#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
   int arr[10];
   int x;
   cout<<"Enter the number of digit you want to feed"<<endl;
   cin>>x;
   for (int i=0;i<x;i++){
    cout<<"Enter the element in array  : ";
    cin>>arr[i];
   }
   for (int i=0;i<x;i++){
    cout<<setw(5)<<arr[i]<<endl;
   }
   cout<<"***************************"<<endl;
   for (int i=0;i<x;i++)
   {
       for (int j=0;j<x-1;j++){
        if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
       }
   }
   for (int i=0;i<x;i++)
    cout<<setw(5)<<arr[i];
    return 0;
}
