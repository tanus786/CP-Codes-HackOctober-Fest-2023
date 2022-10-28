//Time Complexity : O(N)
//Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[], int size)
{
  int max_sum = INT_MIN, ending_index = 0;
  
  for(int i=0; i<size; i++)
  {
    ending_index = ending_index + arr[i];
    if(max_sum < ending_index)
    {
      max_sum = ending_index;
    }
    if(ending_index < 0)
    {
      ending_index = 0;
    }
  }
  return max_sum;
}

int main()
{
  int arr[] = {4,-3,4,-1,-5,1,9,-6};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  int ans = maxSubArraySum(arr,n);
  cout << "Maximum Subarray Sum :" << ans;
  return 0;
}
