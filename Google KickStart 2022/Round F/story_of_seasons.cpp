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

        /* ******  THIS CODE PASSES ONLY THE FIRST TWO TESTS NOT THE FINAL ONE  ****** */

ll x;
set <ll> s;

ll Lower_Bound2(ll d){
	auto it=s.lower_bound(d);
	if(it==s.end()) return -1;
	return (*it);
}

vll l(1e5+5);

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	if(a.ff!=b.ff) return a.ff>b.ff;
	return l[a.ss]<l[b.ss];
}

void solve(int test){
	ll d,n;
	cin>>d>>n>>x;
	vll q(n);
	vector <pair<ll,ll>> v(n);
	for(int i=0 ; i<n ; i++){
		cin>>q[i]>>l[i]>>v[i].ff;
		v[i].ss=i;
	}
	sort(all(v),cmp);
	int cur=0; 
	vector <pair<ll,ll>> fin(d);
	
	for(int i=0 ; i<d ; i++){
		fin[i].ff=0;
		fin[i].ss=0;
		if(i!=0)
			s.insert(i);
	}
	while(cur!=n){
		ll ind=Lower_Bound2(l[v[cur].ss]);
		
		if(ind==-1){
			cur++;
			continue;
		}
		ll avail=x-fin[ind].ss;
		if(q[v[cur].ss]<=avail){
			fin[ind].ss+=q[v[cur].ss];
			if(fin[ind].ss==x){
				auto temp=s.find(ind);
				s.erase(temp);
			}
			fin[ind].ff+=(q[v[cur].ss]*v[cur].ff);
			q[v[cur].ss]=0;
			cur++;
		}
		else{
			fin[ind].ss+=avail;
			auto temp=s.find(ind);
			s.erase(temp);
			q[v[cur].ss]-=avail;
			fin[ind].ff+=(avail*v[cur].ff);
		}
	}
	ll ans=0;
	for(int i=0 ; i<d ; i++){
		ans+=fin[i].ff;
	}
	cout<<"Case #"<<test<<": ";
	cout<<ans<<"\n";
	s.clear();
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