#include<iostream>
#include<queue>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        
        while(index>1){
            int parent=index/2;
            if(arr[index]>arr[parent]){
                swap(arr[index],arr[parent]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void Delete(){
        if(size==0){
            cout<<"empty heap"<<endl;
            return;
        }
        arr[1]=arr[size];
        size=size-1;
        int index=1;
        while(index<size){
            int leftIn=index*2;
            int rightIn=index*2 +1;
            if(leftIn<size && arr[index]<arr[leftIn] && arr[rightIn]<arr[leftIn]){
                swap(arr[index],arr[leftIn]);
            }
            else if(rightIn<size && arr[index]<arr[rightIn] && arr[rightIn]>arr[leftIn]){
                swap(arr[index],arr[rightIn]);
            }
            else{
                return;
            }
        }
    }
};

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i + 1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void HeapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main(){
    Heap h1;
    h1.insert(50);
    h1.insert(55);
    h1.insert(53);
    h1.insert(52);
    h1.insert(54);
    //h1.print();
    h1.Delete();
    //h1.print();

    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2 ; i>0 ;i--){
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    HeapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Using piority queue here"<<endl;
    priority_queue<int> pq; //max heap
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"Element at top "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top "<<pq.top()<<endl;
    cout<<"Size is "<<pq.size()<<endl;

    //min heap
    priority_queue<int,vector<int>,greater<int> > minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout<<"Element at top "<<minheap.top()<<endl;
    return 0;
}