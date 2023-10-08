#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int hash[26]={0};
    for(int i=0;i<s.length();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cout<<"Enter the number of queries: ";
    cin>>q;
    while(q--){
        char c;
        cout<<"Enter the character: ";
        cin>>c;
        cout<<"Frequency of "<<c<<" is: "<<hash[c-'a']<<endl;

    }
    return 0;
}