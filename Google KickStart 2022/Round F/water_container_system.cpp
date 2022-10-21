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

const int N=1e5+7;
vi graph[N];
vi depth(N);
vb vis(N);

void dfs(int vertex,int d){
   vis[vertex]=true;
   depth[vertex]=d;

   for(int child : graph[vertex]){
      if(vis[child]==false){
         dfs(child,d+1);
      }
   }
}

void solve(int test){
	int n,q;
	cin>>n>>q;
	for(int i=0 ; i<n-1 ; i++){
		int a,b;
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	dfs(1,0);
	vi dep(n,0);
	for(int i=1 ; i<=n ; i++){
		dep[depth[i]]++;
	}
	int level=0;
	int cur=0;
	int ans=0;
	for(int i=0 ; i<q ; i++){
		int a;
		cin>>a;
		cur++;
		if(cur==dep[level]){
			level++;
			ans+=cur;
			cur=0;
		}
	}
	cout<<"Case #"<<test<<": ";
	cout<<ans<<"\n";
	for(int i=0 ; i<=n ; i++){
		graph[i].clear();
		vis[i]=false;
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