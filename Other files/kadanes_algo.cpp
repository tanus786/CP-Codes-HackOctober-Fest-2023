#include <bits/stdc++.h>

using namespace std;

int main()

{

  int n;

  cin>>n;

  int arr[n];

  for(int i=0; i<n; i++)

    cin>>arr[i];

  int max_sum = INT_MIN, curr_sum =0;

  for(int i=0; i<n; i++){

   curr_sum += arr[i];

   if(max_sum < curr_sum)

     max_sum = curr_sum;

   if(curr_sum < 0)

     curr_sum = 0;

  }

  cout<<max_sum;

  return 0;

}

