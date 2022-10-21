#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mod 1000000007
#define mod1 998244353

void solve(int test){
   int m,n,p;
   cin>>m>>n>>p;
   p--;
   vi v(n,0);
   vi john(n);
   for(int i=0 ; i<m ; i++){
      if(i==p){
         for(int j=0 ; j<n ; j++){
      
         cin>>john[j];
        
      }
      continue;
      }
      for(int j=0 ; j<n ; j++){
         int temp;
         cin>>temp;
         v[j]=max(v[j],temp);
      }
   }
   ll ans=0;
   for(int i=0 ; i<n ; i++){
      ans+=max(0,v[i]-john[i]);
   }
   cout<<"Case #"<<test<<": ";
   cout<<ans<<"\n";
}
 
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   int t;
   cin>>t;
   int test=1;
   while(t--){
      solve(test);
      test++;
   }
   return 0;
}
