#include <iostream>

using namespace std;


int partition(int*arr,int s,int e){
    int pivot = arr[s];
    int count= 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count ++;
        }
    }
    int pInd= count+s;
    swap(arr[pInd],arr[s]);
    int i=s, j= e;
    while(i<pInd &&j>pInd){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pInd &&j>pInd){
            swap(arr[i++],arr[j--]);
        }
    }return pInd;
}
void quickSort(int *arr, int s, int e){
    if(s>=e){
        return;
    }
   int  pivot = partition(arr,s,e);
   quickSort(arr,s,pivot-1);
   quickSort(arr,pivot+1,e);
}

int main()
{
     int n;
     cin>>n;
     int arr[n];
     for(int i = 0;i<n; i ++){
         cin>>arr[i];
     }
     quickSort(arr,0,n-1);
     for(int i = 0;i<n; i ++){
         cout<<arr[i];
     }

    return 0;
}
