#include<iostream>

using namespace std;
int main()
{
    int arr[100][100];
    int sparse[100][100];
    int i,j,r,c;

    cin>>r;
    cin>>c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
        cin>>arr[i][j];

    }
    }
    int k=0;
    for(i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
           if(arr[i][j]!=0) 
           {
              sparse[0][k] =i;
              sparse[1][k]=j;
              sparse[2][k]=arr[i][j];
           }
           k++;
        }
    }
    for(i=0;i<k;i++)
    {
        for(r=0;r<3;r++)
        {
            cout<<endl<<sparse[r][i];
        }
    }
return 0;
}
    
    
    
    
    
    
    
    
    
