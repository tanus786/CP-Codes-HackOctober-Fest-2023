#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& stalls , int n , int k , int mid)
{
    int cowsCount = 1;
    int cowsDistance = stalls[0];
    for(int i= 0 ; i< n ;i++)
    {
        if(stalls[i] - cowsDistance >= mid)
        {
            cowsCount++;
            if(cowsCount == k)
            {
                return true;
            }
            cowsDistance = stalls[i];
        }
        
    }
    return false;
}

int aggresiveCows(vector<int> &stalls , int n , int k)
{
    sort(stalls.begin() , stalls.end());
    int start = 0;
    int maxi = -1;
    for(int i=0 ; i<n ; i++){
        maxi = max(maxi , stalls[i]);
    }
    int end = maxi;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start <= end)
    {
        if(isPossible(stalls , n , k , mid)){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main()
{
    int n , k; 
    cin >> n >> k;
    vector<int> arr;
    for(int i=0  ;i<n ; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    int ans = aggresiveCows(arr , n , k);
    cout << ans;
    return 0;
}
