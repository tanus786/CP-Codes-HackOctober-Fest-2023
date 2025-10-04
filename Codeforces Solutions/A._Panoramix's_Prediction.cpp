#include<iostream>
using namespace std;
bool prime(int a){
    for(int i=2;i<(a/2)+1;i++){
        if(a%i==0){
             return false;
        }
    }
    return true;
    }
int main(){
    int a,b=0;
    cin>>a>>b;
    int z=0;
    for(int i=a+1;i<b+1;i++){
        if(prime(i)==1){
            z=i;
            break;
        }
    }
    if(z==0){
        cout<<"NO";
    }
    
    else if(z==b){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
 
    return 0;
}
