#include<iostream>

using namespace std;

void SegregateEvenOdd(int arr[], int n)
{

    int i = -1, j = 0;
    while (j != n)
    {
        if (arr[j] % 2 == 0)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
     cout<<"Segregate even and odd numbers"<<"\n";
    cout<<"Starting elements are even and odd number"<<"\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
   int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n; i++){
        cin>>arr[i];
    }
    SegregateEvenOdd(arr, n);
    return 0;
}







// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n; i++){
//         cin>>arr[i];
//     }
//     vector<int>v;
    
//     for(int i=0; i<n; i++){
//         if(arr[i]%2==0){
//             v.push_back(arr[i]);
//         }
//     }
//      for(int i=0; i<n; i++){
//         if(arr[i]%2!=0){
//             v.push_back(arr[i]);
//         }
//     }
//     cout<<"Segregate even and odd numbers"<<"\n";
//     cout<<"Starting elements are even and odd number"<<"\n";
//     for (auto ir = v.begin(); ir != v.end(); ++ir)
//         cout << *ir << " ";
//     return 0;
// }
