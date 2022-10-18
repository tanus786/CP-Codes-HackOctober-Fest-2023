#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<vector<int>> arr, int row, int col, int target)
{
    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = arr[mid / 4][mid % 4];
        if (element == target)
        {
            return 1;
        }

        else if (element > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return 0;
}
int main()
{
    vector<vector<int>> arr{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int row = arr.size();
    int col = arr[0].size();
    
    int k ; // element to search
    cout<<"Enter the element to be searched: ";
    cin>>k;

    if (binarySearch(arr, row, col, k))
    {
        cout << "Element Found!" << endl;
    }

    else
    {
        cout << "Element Not Found!" << endl;
    }

    return 0;
}
