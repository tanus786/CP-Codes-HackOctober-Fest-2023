#include<bits/stdc++.h>
#define ll long long int
using namespace std ;

void solve() {

     ll n,m ;
     cin>>n>>m ;


    ll ans = 0 ;

    for (ll i = 0; i < 30; i++)
    {
         ll val = min(m,n) ;

         if(val%2 == m%2) {
            ans += val ;
            m -= val ;
         }
         else {
            ans += (val-1) ;
            m -= (val-1) ;
         }

         m /= 2 ;
    }

    cout<<ans<<endl;
    

}

int main(){
   ios::sync_with_stdio(0);
   cin.tie(0);  
   ll T ;
   cin>>T ;
   while(T--){
      solve() ;
   }
}
bool isPowerOfTwo (int x)
{
 return x && (!(x&(x-1))); 
}
