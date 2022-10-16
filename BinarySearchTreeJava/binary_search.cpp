#include <bits/stdc++.h>
using namespace std;

// linear search - to search any element in an array linearly
// complexity O(n)
// can be used in sorted/unsorted arrays
int linearSearch(int arr[],int size, int element){  // array to be searched, array size, element to be searched
    for(int i=0;i<size;i++){
        if(arr[i]==element)
        return i;
    }
    return -1;
}

// binary search - to search any element in an array diving size half of subarray
// complexity O(log n)
// can be used in sorted array only
int binarySearch(int arr[],int size, int element){
    int low,mid,high;
    low=0;
    high=size-1;
    // start searching
    while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==element)
    return mid;
    else if(arr[mid]<element)
    low=mid+1;
    else if(arr[mid]>element)
    high=mid-1;
}
    // searching end
    return -1;
}


int main() {
    // unsorted array for linear search
    // int arr[]={22,1,34,5,678,90,444,3};
    // int size=sizeof(arr)/sizeof(int);

    // sorted array for binary search
    int arr[]={22,111,134,155,678,790,1444,3000};
    int size=sizeof(arr)/sizeof(int);
    int element=1444;
    // int index=linearSearch(arr,size,element);
    int index=binarySearch(arr,size,element);
    cout<<index<<endl;
return 0;
}