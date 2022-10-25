#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

void solve(){
	const int X=100000;
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)cin>>a[i],a[i]=X+i-a[i];
	vector<pair<int,vector<int>>> res;
	for(int i=0;i<20;i++){
		vector<int> A;
		for(int j=0;j<n;j++)if(a[j]>>i&1)A.push_back(j+1);
		if(A.empty())continue;
		res.push_back({1<<i,A});
	}
	cout<<res.size()<<'\n';
	for(auto x:res){
		cout<<x.second.size()<<' '<<x.first<<'\n';
		for(auto i:x.second)cout<<i<<' ';cout<<'\n';
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}
