#include<stdio.h>
#include<math.h>
int binary_search(int a[],int key,int l,int h)
{   int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
    
        if(key<a[mid])
            return binary_search(a,key,l,mid-1);
        else
            if(key>a[mid])
                return binary_search(a,key,mid+1,h);
            else
                return mid;
    }
    return -1;

}



int linear_search(int a[], int searchValue,int n) 
{
    int index = -1;

    for (int i = 0; i < n; i++) 
    {
        if (a[i]==searchValue) 
        {
            index = i;
        }
    }

    return index;
} 

int ternary_search(int a[],int key,int l,int h)
{   int mid1 = l + (h-l)/3 ;
    int mid2 = h - (h-l)/3 ;
    if(h>=l)
    {
        if(key==mid1)
            return mid1;
        
        if(key==mid2)
            return mid2;
        
        if(key<a[mid1])
            return ternary_search(a,key,l,mid1-1);
        else
            if (key>a[mid2])
                return ternary_search(a,key,mid2+1,h);
            else
                return ternary_search(a,key,mid1+1,mid2-1);
            
    }
}

int jump_search(int a[],int key,int size)
{   
    int step=sqrt(size);
    int prev=0 ; 
    while(a[step-1]<key)
    {
        prev=step;
        step=step+sqrt(size);
        if(prev>=size)
            return -1;

    }

    while(a[prev]<key)
    {
        prev++;
    }
    if(prev==key)
    {
        return prev;
    }
    return -1;
}

int interpolationSearch(int arr[],int x, int lo, int hi)
{
    int pos;
    
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
    
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
 
        
        if (arr[pos] == x)
            return pos;
 
        
        if (arr[pos] < x)
            return interpolationSearch(arr,x, pos + 1, hi);
 
        
        if (arr[pos] > x)
            return interpolationSearch(arr, x, lo, pos - 1);
    }
    return -1;
}
int exponential_search(int a[],int key,int size)
{   
    
    if(a[0]==key)
        return 0;
    
    int i=1;
    while(i<size&&a[i]<key)
        i=i*2;

    return binary_search(a,key,i/2,i);
    
}

int main()
{
    
    int a[]={0,1,2,3,4,5,6,7,8,9};
    int key=5,l=0,h=10;
    printf("\n1. Element found at %d ",binary_search(a,key,l,h));
    printf("\n2. Element found at %d ",linear_search(a,key,h));
    printf("\n3. Element found at %d ",ternary_search(a,key,l,h));
    printf("\n4. Element found at %d ",jump_search(a,key,h));
    printf("\n5. Element found at %d ",interpolationSearch(a,key,l,h));
    printf("\n6. Element found at %d ",exponential_search(a,key,h));



    return 0;
}