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
   ll rs,rh;
   cin>>rs>>rh;
   int n;
   cin>>n;
   ll mdist=rs+rh;
   vector <pair<ll,int>> v;
   for(int i=0 ; i<n ; i++){
      ll x,y;
      cin>>x>>y;
      ll dis=(((x)*(x))+((y)*(y)));
      if(dis<=((mdist)*(mdist))) v.pb({dis,1});
   }
   int m;
   cin>>m;
   for(int i=0 ; i<m ; i++){
      ll x,y;
      cin>>x>>y;
      ll dis=(((x)*(x))+((y)*(y)));
      if(dis<=((mdist)*(mdist))) v.pb({dis,2});
   }
   cout<<"Case #"<<test<<": ";
   if(v.size()==0){
       cout<<"0 0\n";
       return;
   }
   sort(all(v));
   int ans=0;
   int ini=v[0].ss;
   for(int i=0 ; i<v.size() ; i++){
      if(v[i].ss==ini){
         ans++;
      }
      else break;
   }
   if(ini==1){
      cout<<ans<<" "<<"0\n";
   }
   else{
      cout<<"0 "<<ans<<"\n";
   }
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
