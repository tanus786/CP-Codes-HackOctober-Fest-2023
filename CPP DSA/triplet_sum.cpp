#include <bits/stdc++.h>

using namespace std;

void findTriplet(int A[], int arr_size, int sum) {
	for (int i = 0; i < arr_size - 2; i++) {
		// A[i] == first elem
		for (int j = i + 1; i < arr_size - 1; j++) {
			// A[j] == second elem
			for (int k = j + 1; k < arr_size; k++) {
				// A[k] == third elem
				if (A[i] + A[j] + A[k] == sum) {
					cout << "Triplet satisfied. Numbers are " <<
						A[i] << ", " << A[j] << "and " << A[k];
				}
			}
		}
	}
	cout << "Triplet not satisfied."; 
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
	int sum = 55; 
	int arr_size = sizeof(A) / sizeof(A[0]);
	findTriplet(A, arr_size, sum); 
	return 0;
}

