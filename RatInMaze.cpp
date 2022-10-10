#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    if(x<n && y<n && arr[x][y]==1)
        return true;
    else
        return false;
}

bool RatInMaze(int **arr, int x, int y, int n, int **SolArr){
    if(x==n-1 && y==n-1){
        SolArr[x][y] = 1;
        return true;
    }
    if(isSafe(arr, x, y, n)){
        SolArr[x][y] = 1;
        if(RatInMaze(arr, x+1, y, n, SolArr))
            return true;
        if(RatInMaze(arr, x, y+1, n, SolArr))
            return true;
        SolArr[x][y] = 0; // backtracking
        return false;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the size of maze: ";
    cin>>n;

    int **arr = new int*[n];
    for(int i=0; i<n; i++)
        arr[i] = new int[n];
    
    cout<<"Enter maze:"<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];

    int **SolArr = new int*[n];
    for(int i=0; i<n; i++){
        SolArr[i] = new int[n];
        for(int j=0; j<n; j++){
            SolArr[i][j] = 0;
        }
    }

    if(RatInMaze(arr, 0, 0, n, SolArr)){
        cout<<endl<<"Correct Path:"<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<SolArr[i][j]<<' ';
            }cout<<endl;
        }
    }
    return 0;
}

// Sample input
// 5
// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1