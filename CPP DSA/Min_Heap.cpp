#include<bits/stdc++.h>
using namespace std;

class MinHeap{
	public:
		vector<int> minHeap;
		int heapSize;
		int realSize=0;

		void resizeIt(int size){
			heapSize = size;
			minHeap.resize(heapSize+1);
			minHeap[0] = -1;
		}

		int peek(){
			return minHeap[1];
		}

		void add(int element){
			realSize++;

			if(realSize>heapSize){
				cout<<"Added too many elements!"<<endl;
				realSize--;
				return;
			}

			minHeap[realSize] = element;

			int index = realSize;

			int parent = index/2;

			while(minHeap[parent]>minHeap[index] && index>1){
				swap(minHeap[parent], minHeap[index]);
				index = parent;
				parent = index/2;
			}
		}

		int pop(){

			if(realSize<1){
				cout<<"Not enough element in the Heap!";
				return INT_MAX;
			} else{
				int removed = minHeap[1];

				minHeap[1] = minHeap[realSize];
				realSize--;
				int index = 1;

				while(index<=realSize/2){
					int left = index*2;
					int right = (index*2) + 1;

					if(minHeap[index]>minHeap[left] || minHeap[index]>minHeap[right]){
						if(minHeap[left]<minHeap[right]){
							swap(minHeap[left], minHeap[index]);
							index = left;
						}
						else{
							swap(minHeap[right], minHeap[index]);
							index = right;
						}
					}
					else break;
				}
				return removed;
			}
		}

		int size(){
			return realSize;
		}

		void print(){
			if(realSize==0){
				cout<<"NO ELEMENT";
				return;
			}
			for(int i=1; i<=realSize; i++) cout<<minHeap[i]<<" ";
			cout<<endl;
			return;
		}
};

int main(){
	MinHeap minHeap;
	minHeap.resizeIt(3);

	minHeap.add(3);
    minHeap.add(1);
    minHeap.add(2);

    minHeap.print();

    cout<<minHeap.peek()<<endl;

    cout<<minHeap.pop()<<endl;

    minHeap.print();
    minHeap.add(4);

    minHeap.add(5);

    minHeap.print();
    return 0;
}