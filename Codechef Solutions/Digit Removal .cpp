#include<bits/stdc++.h>
using namespace std;
int isMin(int n, int d){
    int newN = n, rem , count =0, c = 0;
    while(newN>0){
        rem = newN % 10;
        newN = newN /10;
        c++;
        if(rem == d){
            newN = newN*pow(10,c)+(rem+1)*pow(10,c-1);
            count = newN -n;
            c = 0;
        }
    }
    return count;
}
int main()
{
  int t;
  cin>>t;
  while(t--){
      int n, d;
      cin>>n>>d;
      cout<<isMin(n, d) <<endl;
  }
  return 0;
}
