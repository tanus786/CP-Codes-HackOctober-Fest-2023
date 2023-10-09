#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
       int uc=n-1;
       int ur=n-1;
       int lc=0;
       int lr=0;
       int count=0;
       vector<vector<int>>ans(n,vector<int>(n,0));
       char direction='r';
       int i=0,j=0;
       while(count!=n*n)
       {
           count++;
           ans[i][j]=count;
           if(direction=='r')
           {
               if(j==uc)
                  {
                      i++;
                      direction='d';
                      lr++;
                  }
                else
                    j++;     
           }
           else if(direction=='d')
           {
               if(i==ur)
               {
                   j--;
                   direction='l';
                   uc--;
               }
               else
                 i++;
           }
           else if(direction=='l')
           {
               if(j==lc)
               {
                   i--;
                   direction='u';
                   ur--;
               }
               else
                 j--;
           }
           else if(direction=='u')
           {
               if(i==lr)
               {
                   j++;
                   direction='r';
                   lc++;
               }
               else
                  i--;
           } 
       }
       return ans;
        
    }
};