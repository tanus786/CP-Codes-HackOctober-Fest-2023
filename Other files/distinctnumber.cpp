//Link:-
//....................AUTHOR:-Anurag
 
// Pragmas
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
//bultin functions
#define setbits(x) __builtin_popcountll(x) ///No of set bits 
#define tzrobits(x) __builtin_ctz(x) ///Trailing zeros 
#define lzrobits(x) __builtin_clz(x) ///Leading zeros 
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
    ll n;       \
    cin >> n;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define input(v1,n) \
    for(int i=0;i<n;i++)    \
    {   \
        cint(x);    \
        v1.emplace_back(x);     \
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

int mod = 1e9 + 7;//1e9-7
const ll inf = 1e18;
const int N = 200007;
const double PI =  acos(-1.0);
 
#ifndef ONLINE_JUDGE
#define debug(x)cerr << #x << " ";_print(x);cerr << endl;
#else
#define debug(x)
#endif
 
void _print(unsigned t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
 void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
//************************************************************************************************
 
// vector<vll>adj(N);
// vll vis(N,0);   
// vector<vi> dp(N+1,vi(N+1,0)); 
int binpow(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
int invprime(int a, int b) {return binpow(a, b - 2, b);}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, invprime(b, m), m) + m) % m;} 
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
int lcm(int a,int b){return a*b/(__gcd(a,b));}
//Maths
 
 
void soln()
{
    cint(n);
    cint(k);

    vll arr,t1;
    input(arr,n);

    sort(all(arr));
    ll ans=0ll,maxi=arr[n-1],z=0,check=0;
    int st=1-(arr[n-1]==2*n);
    for (int i = 1; i <= 2*n; ++i)
    {
        if(arr[z]!=i)
        {
            if(i<=maxi)check++;
            t1.pb(i);
        }
        else z++;
    }
    // if(k==1)
    // {
    //     if(len(t1)==0){cout<<0;return;}
    //     cout<<2*n-t1[0];
    //     return ;
    // }

    z=0;
    for (int i = st; i < k; ++i)
    {
        ans+=max(2*n-t1[z],maxi-t1[z]);
        z++;
    }

    if(k<=check)
    {
        ll ans1=0ll;
        for (int i = 0; i < k; ++i)
        {
            ans1+=abs(maxi-t1[i]);
        }
        ans=max(ans1,ans);
    }

    cout<<ans;
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
    // tt=1;
    cin>>tt;
    //int p=1;


    while(tt--)
    {
        //cout<<"Case #"<<p<<": ";
        soln();
        //p++;
        line;
    }
    return 0;
}