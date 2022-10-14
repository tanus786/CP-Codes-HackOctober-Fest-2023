// C++ implementation of the problem
// Next permutation
#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int> &nums)
{
    int i, index1, index2;

    for (i = nums.size() - 1; i > 0; i--)
    {
        if (nums[i - 1] < nums[i])
        {
            index1 = i - 1;
            break;
        }
    }
    if (i == 0)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[index1])
            {
                index2 = i;
                break;
            }
        }
        swap(nums[index1], nums[index2]);
        reverse(nums.begin() + index1 + 1, nums.end());
    }
}

int main()
{
    int n;
    vector<int> arr;
    cout << "Enter the size of array: ";
    cin >> n;

    int num, i = 0;
    while (i < n)
    {
        cout << "Enter arr[" << i << "]: ";
        cin >> num;

        arr.push_back(num);

        i++;
    }

    cout << "Entered number: ";
    for (auto i : arr)
    {
        cout << i;
    }

    nextPermutation(arr);

    cout << "\nNext permutation: ";
    for (auto i : arr)
    {
        cout << i;
    }
}

// This code is contributed by Omkar Jahagirdar (Github: omkar3602)