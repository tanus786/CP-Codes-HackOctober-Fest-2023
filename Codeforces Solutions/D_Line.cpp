#include <bits/stdc++.h>
using namespace std;
    
using ll = long long;
#define forl(xyz) for (ll i = 0; i < xyz; i++)
#define in(x) cin >> x;
#define in2(x, y) cin >> x >> y;
#define in3(x, y, z) cin >> x >> y >> z;
#define out(x) cout << x;
#define out2(x, y) cout << x << ' ' << y<<endl;
#define out3(x, y, z) cout << x << ' ' << y << ' ' << z<<endl;
#define space cout << ' ';
#define iarr(name,x) int name[x]={0};
#define nforl(mno, pqr) for (ll i = mno; i < pqr; i++)
#define line cout << endl;
int main()
{
ll  test1;
in(test1)
while(test1--)
{  ll n,sum1 = 0;
    in(n);
    string s;
    in(s);
bool flag = 0;
    
ll count1 = 0;
    
forl(n){
if(s[i]=='L')sum1+=i;
else sum1 = sum1 + n - i - 1;
}
ll x = 0;
    
while(x< n/2 && count1 <=n ){
    
if(s[x]== 'L'){s[x]='R';
sum1 = sum1 + n - x - 1 - x;
cout<<sum1<<" ";
count1++;}
    
else{
    if(s[n-x-1]== 'R'){s[n-x-1]='L';
    sum1 = sum1 + n - x - 1 - x;
    cout<<sum1<<" ";
    count1++;}
    x++;
}
    
}
    
forl(n-count1)cout<<sum1<<" ";
    
    
cout<<endl;
}
return 0;
}