
#include <iostream>
using namespace std;

void swap(int *a, int *b);

void segregateEvenOdd(int arr[], int size)
{

	int left = 0, right = size-1;
	while (left < right)
	{
	
		while (arr[left] % 2 == 0 && left < right)
			left++;

		while (arr[right] % 2 == 1 && left < right)
			right--;

		if (left < right)
		{
	
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* Driver code */
int main()
{
	int arr[] = {12, 34, 45, 9, 8, 90, 3};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int i = 0;

	segregateEvenOdd(arr, arr_size);

	cout <<"Array after segregation ";
	for (i = 0; i < arr_size; i++)
		cout << arr[i] << " ";

	return 0;
}
