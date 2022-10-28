#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define f first
#define mt make_tuple
#define s second
#define ll long long
#define NO cout << "NO" << '\n'
#define YES cout << "YES" << '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int,int> mii;
class comp{
public:
    bool operator()(pair<int,int>&t,pair<int,int>&c){
        return t.f > c.f;
    }
};
class comp_2{
public:
    bool operator()(pair<int,int>&t,pair<int,int>&c){
        return t.s > c.s;
    }
};
int main() {
    int test;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> test;
    rep(i, 0, test) {
        int n;
        cin >> n;
        if (n==1){
            cout << "Bob" << '\n';
            continue;
        }
      vi arr(n);
      rep(j,0,n) {
          cin >> arr[j];
      }
      int dif = 0;
      int one = 0;
      int z = 0;
      if (arr[0]==arr[n-1]){
          if (arr[0]){
              one++;
          } else {
              z++;
          }
      }
      int p = 1;
      while (p < n){
          if (arr[p]==arr[p-1]){
              if(arr[p]){
                  one++;
              } else {
                  z++;
              }
          }
          p++;
      }
      dif = min(z,one);
      if (dif%2==0){
          cout << "Bob" << '\n';
      } else {
          cout << "Alice" << '\n';
      }
    }
}
       
