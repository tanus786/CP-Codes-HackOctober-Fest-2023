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
    for(int i=0;i<n;i++)     \
    {     \
        cint(x);     \
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

// vector<vll>adj(N);
// vll vis(N,0);   
// vector<vi> dp(N+1,vi(N+1,0)); 
int n,c;
int func(int num,vll array)
{
    int cows=1,pos=array[0];
    for (int i=1; i<n; i++)
    {
        if (array[i]-pos>=num)
        {
            pos=array[i];
            cows++;
            if (cows==c)
                return 1;
        }
    }
    return 0;
}

void soln()
{
    cin>>n>>c;
    vll array;
    input(array,n);
    sort(all(array));
    int ini=0,last=array[n-1],max=-1;
    while (last>ini)
    {
        int mid=(ini+last)/2;
        if (func(mid,array))
        {
            if (mid>max)
                max=mid;
            ini=mid+1;
        }
        else
            last=mid;
    }
    cout<<max;
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
    cin>>tt;

    while(tt--)
    {
        soln();
        line;
    }
    return 0;
}