#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
	public:
		vector<int> maxHeap;
		int heapSize;
		int realSize=0;

		void resizeIt(int size){
			heapSize = size;
			maxHeap.resize(heapSize+1);
			maxHeap[0] = -1;
		}

		int peek(){
			return maxHeap[1];
		}

		void add(int element){
			realSize++;

			if(realSize>heapSize){
				cout<<"Added too many elements!"<<endl;
				realSize--;
				return;
			}

			maxHeap[realSize] = element;

			int index = realSize;

			int parent = index/2;

			while(maxHeap[parent]<maxHeap[index] && index>1){
				swap(maxHeap[parent], maxHeap[index]);
				index = parent;
				parent = index/2;
			}
		}

		int pop(){

			if(realSize<1){
				cout<<"Not enough element in the Heap!";
				return INT_MAX;
			} else{
				int removed = maxHeap[1];

				maxHeap[1] = maxHeap[realSize];
				realSize--;
				int index = 1;

				while(index<=realSize/2){
					int left = index*2;
					int right = (index*2) + 1;

					if(maxHeap[index]<maxHeap[left] || maxHeap[index]<maxHeap[right]){
						if(maxHeap[left]>maxHeap[right]){
							swap(maxHeap[left], maxHeap[index]);
							index = left;
						}
						else{
							swap(maxHeap[right], maxHeap[index]);
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
			for(int i=1; i<=realSize; i++) cout<<maxHeap[i]<<" ";
			cout<<endl;
			return;
		}
};

int main(){
	MaxHeap maxHeap;
	maxHeap.resizeIt(3);

	maxHeap.add(1);
    maxHeap.add(2);
    maxHeap.add(3);

    maxHeap.print();

    cout<<maxHeap.peek()<<endl;

    cout<<maxHeap.pop()<<endl;

    maxHeap.print();
    maxHeap.add(4);
    maxHeap.add(5);
    cout<<maxHeap.pop()<<endl;
    maxHeap.add(5);

    maxHeap.print();
    return 0;
}