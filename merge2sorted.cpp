#include<iostream>
#include<queue>
using namespace std;
void solve(vector<int>a,vector<int>b, int n, int m, int answer[]){
    int i=0, j=0;
    int k=0;
        while(i<n && j<m){
            if(a[i]<b[j]){
                answer[k++] = a[i];
                i++;
            }
            else{
                answer[k++] = b[j];
                j++;
            }
        }
        while(i<n){
            answer[k++] = a[i];
            i++;
        }
        while(j<m){
            answer[k++] = b[j];
            j++;
        }
        for(int it=0;it<n+m;it++){
            cout<<answer[it]<<" ";
        }
}
int main(){
    vector<int>arr1 = {1,8};
    int n = 2;
    vector<int>arr2 = {10,11};
    int m = 2;
    int ans[n+m];
    solve(arr1,arr2,n,m,ans);

}