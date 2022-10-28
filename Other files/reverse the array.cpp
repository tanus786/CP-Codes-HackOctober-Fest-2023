#include <iostream>

using namespace std;
void reverse(int arr[],int size)//code for reverse the array
{
    int start=0;
    int end = size-1;
    while(start<= end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }

}
void print(int arr[],int size)//code for print the array
{
     cout<<"enter the value in the array"<<endl;
    for(int i=0;i<size;i++){
        cout << arr[i]<<" ";
}
cout<<endl;
}
int main(){
    int size;
    cout<<"enter the size of array"<<endl; 
    cin>>size;
    int arr[100];
     cout<<"enter the value in the array"<<endl; 
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<" the value in the array"<<endl;
    for(int i=0;i<size;i++){
        cout<<" "<<arr[i];
    }
     cout<<endl;
    reverse(arr,size);
    print(arr,size);

}