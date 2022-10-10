#include<bits/stdc++.h>
using namespace std;

void SeiveOfEratosthenes(int num){
    int arr[num+1] = {0};
    for(int i=2; i<=num; i++){
        if(arr[i]==0){
            for(int j=i*i; j<=num; j+=i){
                arr[j] = 1;
            }
        }
    }

    for(int i=2; i<=num; i++){
        if(arr[i]==0)
            cout<<i<<' ';
    }cout<<endl;
}

void PrimeFactorisation(int num){
    int arr[num+1];
    for(int i=0; i<=num; i++)
        arr[i] = i;

    for(int i=2; i<=num; i++){
        if(arr[i]==i){
            for(int j=i*i; j<=num; j+=i){
                if(arr[j]==j){
                    arr[j] = i;
                }
            }
        }
    }

    while(num!=1){
        cout<<arr[num]<<' ';
        num /= arr[num];
    }cout<<endl;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    SeiveOfEratosthenes(n);
    PrimeFactorisation(n);
    return 0;
}