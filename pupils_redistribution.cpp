 #include<bits/stdc++.h>
 using namespace std;
 int main(){
     int n;
     cin>>n;
     int a[n],b[n];
     int fa[6]={0},fb[6]={0},c[6]={0};
     for(int i=0;i<n;i++){
         cin>>a[i];
     }
     for(int i=0;i<n;i++){
         cin>>b[i];
     }
     for(int i=0;i<n;i++){
         fa[a[i]]++;
         fb[b[i]]++;
     }
     bool f=1;
     int s=0;
     for(int i=1;i<6;i++){
         c[i]=abs(fa[i]-fb[i]);
         s+=c[i]/2;
         if(c[i]%2!=0){
             f=0;
            
         }
     }
     if(f==0){
         cout<<"-1\n";
     }
     else{
         cout<<s/2<<"\n";
     }
     
 }