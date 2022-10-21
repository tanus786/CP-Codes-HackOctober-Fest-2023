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

bool cmp1(pair<string,int> a,pair<string,int> b){
	if(a.ff!=b.ff) return a.ff<b.ff;
	return a.ss<b.ss;
}

bool cmp2(pair<int,int> a,pair<int,int> b){
	if(a.ff!=b.ff) return a.ff<b.ff;
	return a.ss<b.ss;
}

void solve(int test){
	int n;
	cin>>n;
	vector <pair<string,int>> c(n);
	vector <pair<int,int>> d(n);
	for(int i=0 ; i<n ; i++){
		cin>>c[i].ff>>d[i].ff>>c[i].ss;
		d[i].ss=c[i].ss;
	}
	sort(all(c),cmp1);
	sort(all(d),cmp2);
	int ct=0;
	for(int i=0 ; i<n ; i++){
		if(c[i].ss==d[i].ss) ct++;
	}
	cout<<"Case #"<<test<<": ";
	cout<<ct<<"\n";
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