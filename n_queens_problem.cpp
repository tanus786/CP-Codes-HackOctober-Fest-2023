#include<bits/stdc++.h>
using namespace std;
int x[100] ;
int c=0;
int place(int k  , int i)
{
    for(int j=1 ; j<k ; j++)
    {
        if((x[j]==i)||(abs(x[j]-i))==abs(j-k)) return 0;
    }
    return 1;
}
void nqueens(int k  , int n )
{
    for(int i=1 ; i<=n ;  i++)
    {
        if(place(k , i))
        {
            x[k]=i;
            if(k==n)
            {
                c++;
                cout<<"\n";
                for(int j=1 ; j<=n ; j++)
                {
                    for(int p=1 ; p<=n ; p++)
                    {
                        if(x[j]==p)
                            cout<<"q\t";
                        else cout<<"#\t";
                    }
                    cout<<endl;
                    cout<<endl;
                }
            }
            else nqueens(k+1 , n );
        }
    }
}

int main()
{
    int n ;
    cout<<"ENTER THE NUMBER OF QUEENS :";
    cin>>n;
    nqueens(1 , n );
    if(c) cout<<"\nNUMBER OF SOLUTIONS :"<<c;
    else cout<<"\nNO SOLUTIONS";

}
