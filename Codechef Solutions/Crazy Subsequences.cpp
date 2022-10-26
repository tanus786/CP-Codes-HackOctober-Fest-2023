#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#include <stdio.h>
int even() {
  int n;
  cout << "Enter an integer: ";
  cin >> n;
  if ( n % 2 == 0)
    cout << n << " is even.";
  else
    cout << n << " is odd.";
  return 0;
}
string dragon(string animal){
    string zebra;
    if(animal.size()>=3&&animal[animal.size()-1]=='1'&&animal[animal.size()-2]=='1'){
        animal[animal.size()-1]='$';
        for(ll i=0;i<(ll)animal.size();++i)
        if(animal[i]=='0'){
            animal[i]='$';
            break;
        }
        for(ll i=0;i<(ll)animal.size();++i)
            if(animal[i]!='$')
            zebra+=animal[i];
            return zebra;
    }else return animal;
}
ll crow(string strand){
    vector<ll> esla;
    for(ll i=0;i<strand.size();++i){
        if(strand[i]=='0') esla.push_back(i);
    }
    if(esla.size()==1) return 1;
    if(esla[esla.size()-1]==esla[esla.size()-2]) return 1;
    for(ll i=esla[0];i<esla[esla.size()-2];++i)
    if(strand[i]=='1') return 1;
    return 2;
}
void summary(){
    string sand,animal;
    ll tea=0,parrot=0;
    cin>>sand;
    for(ll i=(ll)sand.size()-1;i>=0;--i)
    if(sand[i]=='1'){
        for(ll j=0;j<=i;++j)
        animal+=sand[j];
        break;
    }else tea++;
    if(tea==(ll)sand.size()){
        cout<< sand<<"\n";
        return;
    }
    sand=animal;
    for(ll i=0;i<(ll)sand.size();++i)
    if(sand[i]=='0') parrot++;
    if(parrot==0){
        cout<<sand;
        for(ll i=0;i<tea;++i) putchar('0');
        putchar('\n');
        return;
    }
    if(parrot%2==0){
        ll land=2147482647,rat=-2147483648;
        for(ll i=0;i<(ll)sand.size();++i)
        if(sand[i]=='0'){
            land=min(land,i);
            rat=max(rat,i);
        }
        for(ll i=land;i<=rat;++i)
        if(sand[i]=='1'){
            for(ll j=0;j<(ll)sand.size();++j)
            if(sand[j]=='1') putchar('1');
            for(ll i=0;i<tea;++i) putchar('0');
            putchar('\n');
            return;
        }
        if(tea>=2){
            for(ll i=0;i<(ll)sand.size();++i)
            if(sand[i]=='1') putchar('1');
            for(ll i=0;i<tea-2;++i) putchar('0');
            putchar('\n');
            return;
        }
        if(tea==1){
            animal="";
            for(ll i=(ll)sand.size()-1;i>=0;--i)
            if(sand[i]=='0'){
                sand[i]='$';break;
            }
            for(ll i=0;i<(ll)sand.size();++i)
            if(sand[i]=='$') animal+='0'; else
            if(sand[i]=='1') animal+='1';
            sand=animal;
            cout<<dragon(sand)<<"\n";
            return;
        }
        if(tea==0){
            ll _=0;animal="";
            for(ll i=(ll)sand.size()-1;i>=0;--i)
            if(sand[i]=='0'){
                sand[i]='$';
                _++;
                if(_==2)
                break;
            }
            for(ll i=0;i<(ll)sand.size();++i)
            if(sand[i]=='$') animal+='0'; else
            if(sand[i]=='1') animal+='1';
            sand=animal;
            cout<<dragon(dragon(sand))<<"\n";
            return;
        }
    }
    ll esla=0,L=crow(sand);animal="";
    for(ll i=sand.size()-1;i>=0;--i)
    if(sand[i]=='0'){
        esla++;
        if(esla==L) sand[i]='$';
    }
     //         cin>>   for(long long i=0;i<x;i++)
	   // {
	   //     for(long long j=0;j<y;j++)
	   //     {
	   //         cin>>b[i][j];brr[r++]=b[i][j];s1.insert(b[i][j]);
	   //         m[b[i][j]].push_back(k);
	   //         k++;
	   //     }
	   // }r=0;
	   //  for(int i=0;i<x;i++)
	   // {
	   //     for(int j=0;j<y;j++)
	   //     {a[i][j];arr[r++]=a[i][j];s.insert(a[i][j]);
    for(ll i=0;i<(ll)sand.size();++i)
    if(sand[i]=='1') animal+='1';
    else if(sand[i]=='$') animal+='0';
    sand=animal;
    if(tea!=0){
        for(ll i=0;i<(ll)sand.size();++i)
        if(sand[i]=='1') putchar('1');
        for(ll i=0;i<tea-1;++i)
        putchar('0');
        putchar('\n');
        return;
    }
    cout << dragon(animal) <<"\n";
}
int main() {
  // your code goes here
  ll t;
  cin>>t;
  while(t--)
 {
      summary();
  }
  return 0;
}
