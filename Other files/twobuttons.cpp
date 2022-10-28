//Link:-https://codeforces.com/problemset/problem/520/B
//....................AUTHOR:-Anurag
 
#include <bits/stdc++.h>

using namespace std;
#define lastset(x)   __builtin_ffs(x) //last set bit position(1-based)
 
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define arrmin(x) *min_element(all(x))
#define arrmax(x) *max_element(all(x))
#define arrsum(x) accumulate(all(x), 0LL)
#define arrpre(x) partial_sum(all(x), x.begin())
#define arrsuf(x) partial_sum(allr(x), x.rbegin()) 
#define len(x) (int) (x).size()
#define pb push_back
#define eb emplace_back
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define cint(n) \
    ll n;   	\
    cin >> n;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define input(v1,n) \
    for(int i=0;i<n;i++) 	\
    { 	\
        cint(x); 	\
        v1.emplace_back(x); 	\
    }
#define input1(v1,n) \
    v1.emplace_back(0);\
    for(int j=1;j<=n;j++)   \
    {   \
        cint(x);    \
        v1.emplace_back(x);     \
    }
#define strline(s)               \
    string s;                      \
    getline(cin, s);               \
    if (s == "" || s == "\n") \
      getline(cin, s);
#define ft first
#define sc second
#define line cout<<'\n'
#define precise(digits) fixed << setprecision(digits)
 
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

// vector<vll>adj(N);
// vll vis(N,0);   
// vector<vi> dp(N+1,vi(N+1,0)); 
 
void soln()
{
    cint(n);
    cint(m);
    if (n >= m)
        cout << (ll)abs(n - m);//Always when n>m then ans is n-m as at that time we can't divide by 2 to get more smaller elements 
    else
    {
        int ans = 0;
        // If (m>n)
        while(m>n)
        {
        	if(m&1)m++,ans++;// If m is odd then increase by 1 as it makes the m divisible by 2
        	if(m==n){cout<<ans;return;}// when m==n at that time ans is reached so don't do anything
        	m/=2;// Divide by 2
        	ans++;
        }
		if(m==n){cout<<ans;return;}// when m==n at that time ans is reached so don't do anything
        // ans--;
        ans+=(n-m);// Finally increase it by the difference
        cout << ans;
    }
}
 
int main()
{
    int tt;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    tt=1;
    soln();
    return 0;
}