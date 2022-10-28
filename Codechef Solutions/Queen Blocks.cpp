#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int main()
{
    int x,y,i,j,k,t,n;
    cin >> t ;
    while(t--){
        cin >> x >> y ;
        int chess[9][9] = {} ;
        chess[x][y] = 1 ;
        if((x==1||x==8)&&(y==1||y==8)){
            x++; y+=2;
            if(x>8)
                x -=2;
            if(y>8)
                y -=4;
            chess[x][y] = 2;
        }
        else if(x==1 || y==1){
            if(x==1){
                chess[3][y+1] =2;
                chess[3][y-1] =2;
            }
            else {
                chess[x-1][3] = 2;
                chess[x+1][3] = 2;
            }
        }
        else if(x==8||y==8){
            if(x==8){
                chess[6][y+1] = 2;
                chess[6][y-1] = 2;
            }
            else {
                chess[x+1][6] = 2;
                chess[x-1][6] = 2;
            }
        }
        else {
            if((x+2<=8)&&(y+3<=8)){
                chess[x+2][y-1] = 2;
                chess[x-1][y+3] = 2;
            }
            else if(x+2<=8){
                chess[x+2][y+1] = 2;
                chess[x-1][y-3] = 2;
            }
            else if(y+3<=8){
                chess[x-2][y-1] = 2;
                chess[x+1][y+3] = 2;
            }
            else {
                chess[x-2][y+1] = 2;
                chess[x+1][y-3] = 2;
            }
        }
        /// output ...
        for(i=1;i<9;i++){
            for(j=1;j<9;j++)
                cout << chess[i][j] << " " ;
            cout << endl ;
        }
    }
    return 0;
}
       
