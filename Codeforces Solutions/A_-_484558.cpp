#include<bits/stdc++.h>
using namespace std;

void jayShreeRam(){
    int n;
    cin >> n;
    int quot = n/16;
    int rem = n%16;
    if(quot >= 10) cout << char('A'+quot-10);
    else cout << quot;
    if(rem >= 10) cout << char('A'+rem-10) << "\n";
    else cout << rem << "\n";
}

int main(){
    int t = 1;
    for(int i = 0; i < t; i++){
        jayShreeRam();
    }
    return 0;
}