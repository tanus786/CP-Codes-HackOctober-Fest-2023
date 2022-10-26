#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, s1;
    cin >> s;
    s1 = "hello";
    int j = 0, cnt = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == s1[j]){
            j++;
            cnt++;
        }
        if(cnt == 5) break;
    }
    if(cnt == 5) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}