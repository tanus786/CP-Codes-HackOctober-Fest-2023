#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, s1;
    cin >> s;
    cin >> s1;
    reverse(s1.begin(), s1.end());
    if(s1==s) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}