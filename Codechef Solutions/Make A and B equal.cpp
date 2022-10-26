#include<bits/stdc++.h>
// #pragma GCC optimize ("03")
// #pragma GCC optimize ("sse4")
#define ll   long long int
#define vi   vector<int>
#define uos	 unordered_set<int>
#define all(x)      	( x.begin() , x.end() )
#define sortvi(x)    	sort(x.begin() , x.end())
#define eb				emplace_back
#define nline 			"\n"
using namespace std;
/****************************************************************************************************/
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
    int t ;
    cin>>t;
    while(t--){
        int a , b , c = 0 ;
        cin>>a>>b;
        int x = min(a , b) ;
        int y = max(a , b );
        while( x < y ){
            x*=2;
        }
        if( x == y ) cout<<"YES"<<nline;
        else cout<<"NO"<<nline;
    }
}
