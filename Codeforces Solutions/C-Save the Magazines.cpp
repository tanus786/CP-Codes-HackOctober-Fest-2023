//Task link-https://codeforces.com/contest/1743/problem/C
//Save_the_Magazines
//SWASTIK_RAGHUNATH@IIT BHU ##Swastik@3025
//Competitive programming_boilerplatecode
#include<iostream>
#include<cmath>
#include<string>
#include<climits>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<bitset>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<iterator>
#include<stack>
#include<queue>
#include<list>
#include<numeric>
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define all(x) x.begin(),x.end()
#define vi vector<int>
#define f first
#define s second
#define fi(i,x,n) for(int i=x;i<n;i++)
#define fl(i,x,n) for(ll i=x;i<n;i++)
const int m=1e9+7;
using namespace std;
int main(){
    fastio;
    int t;cin>>t;
    while(t--){
      ll n;cin>>n;string s;cin>>s;ll arr[n];ll x=0;ll y=INT_MIN;
      for(ll i=0;i<n;i++){
        cin>>arr[i];
      }
      for(ll i=0;i<n;i++){
        if(s[i]=='1'){
           x=x+max(arr[i],y);
        }
        if(s[i]=='0'||arr[i]<y){
            y=arr[i];
        }
      }
      cout<<x<<endl;
    }
return 0;
}
