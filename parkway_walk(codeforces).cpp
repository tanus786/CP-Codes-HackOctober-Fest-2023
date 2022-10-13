#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n];
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum=sum+a[i];
		}
		if(sum<=m){
			cout<<0<<endl;
		}
		else{
			cout<<sum-m<<endl;
		}
	}
}
