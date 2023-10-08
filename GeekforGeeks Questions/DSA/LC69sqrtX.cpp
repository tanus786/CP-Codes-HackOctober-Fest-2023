#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x==0 || x==1){
            return x;
        }
    int start=2;
    int end=x;
    int range=end-start;
    int mid=start+(range/2);
    while (start<=end){
        if (mid==x/mid){
            return mid;
        }
        else if (mid<x/mid){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        range=end-start;
        mid=start+(range/2);

    }
    return mid;
    };

};
int main(){
    int x;
    cin>>x;
    Solution s;
    cout<<s.mySqrt(x);
    return 0;
    
}