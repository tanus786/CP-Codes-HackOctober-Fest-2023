// link to the problemset

// https://cses.fi/problemset/


#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2*100005];
int seg[8*100005];
void build(int idx,int low,int high){
    if(low==high){
        seg[idx]=a[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*idx+1,low,mid);
    build(2*idx+2,mid+1,high);
    seg[idx] = (seg[2*idx+1]+seg[2*idx+2]);
}
int sum(int idx,int low,int high,int l,int r){
    if(low>=l &&  high<=r){
        return seg[idx];
    }
    if(r<low || high<l)return 0;
    int mid = (low+high)/2;
    int left = sum(2*idx+1,low,mid,l,r);
    int right= sum(2*idx+2,mid+1,high,l,r);
    return (left+right);   
}
void update(int idx,int low,int high,int i,int val){
    if(low==high){
        seg[idx] = val;
        return;
    }
    int mid = (low+high)/2;
    if(i<=mid){
        update(2*idx+1,low,mid,i,val);
    }else{
        update(2*idx+2,mid+1,high,i,val);
    }
    seg[idx] = seg[2*idx+1]+seg[2*idx+2];
}
signed main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    build(0,0,n-1);
    while(q--){
        int type,l,r;
        cin>>type>>l>>r;
        if(type==1){
            update(0,0,n-1,l-1,r);
        }else{
            cout<<sum(0,0,n-1,l-1,r-1)<<"\n";    
        }
    }
}