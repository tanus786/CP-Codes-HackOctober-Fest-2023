// Given a binary array, we need to convert this array into an array that either contains all 1s or all 0s.  We need to do it using the minimum number of group flips. 
// C++ program to find the minimum
// group flips in a binary array
#include <iostream>
using namespace std;

void printGroups(bool arr[], int n) {

for (int i = 1; i < n; i++) {
	
	
	if (arr[i] != arr[i - 1]) {
	if (arr[i] != arr[0])
		cout << "From " << i << " to ";
	else
		cout << (i - 1) << endl;
	}
}

if (arr[n - 1] != arr[0])
	cout << (n - 1) << endl;
}

int main() {
    int n=0;
    cin>>n;
    bool arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
printGroups(arr, n);
return 0;
}
