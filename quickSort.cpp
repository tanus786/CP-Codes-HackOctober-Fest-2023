#include<iostream>
using namespace std;
      int partition(int *arr, int s, int e)
      { 
                 
    if(s>=e)  // leap of faith rkh bro ye , single element hoga jab s= 3 hoga toh sidha return kuki vo phle se sorted
    // he aese algo bna he
    return ;

    int i=s;
    int j= e;
    int count;
    for(i=s+1;i<=e;i++)
    {
        if(arr[s]>=arr[i])
        {
               count++;
        }
    }
    int pivot = s+count;
    swap(arr[s],arr[s+count]);
               while(i<pivot && j>pivot)
               {
                     while(arr[i] <=arr[s+count])
                     {
                        i++;
                     }
                     while(arr[j]>arr[s+count]){
                        j--;
                     }
                     while(arr[i]>arr[s+count] && arr[j]<arr[s+count])
                     {
                        swap(arr[i],arr[j]);
                        i++;
                        j--;
                     }

                     return  s+count;
               }




      }
 void quicksort(int *arr,int s,int e)
{
    if(s>=e)   //(0,0) toh rok do ret
    {
return ;
    }
        int p =partition(arr,s,e);
           quicksort(arr,s,p-1);
           quicksort(arr,p+1,e);
return ;
}
int main(){
      int arr[6];
      for(int i=0;i<6;i++)
      {
        cin>>arr[i];
      }
      quicksort(arr,0,5);
     

    return 0;
}