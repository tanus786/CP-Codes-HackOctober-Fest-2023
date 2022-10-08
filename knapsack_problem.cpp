#include<bits/stdc++.h>
using namespace std;
int knapsack(int w[] , int p[] , int n , int m )
{
    if(m==0) return 0;
    if(n==0) return 0;
    if(w[n-1]>m) return knapsack(w , p , n-1 , m);
    return max(knapsack(w , p , n-1 , m ) , p[n-1]+knapsack(w , p , n-1 , m-w[n-1]));
}
int main()
{
    int i ,  n , m;
    cout<<"\nENTER THE NUMBER OF ELEMENTS";
    cin>>n;
    int w[n]; // for the weights
    int p[n]; //for the value of each weights
    cout<<"\nENTER THE WEIGHTS AND PRICES OF ALL THE ITEMS"<<endl;
    for(int i=0 ;  i<n ; i++)
    {
        cin>>w[i]>>p[i];
    }
    cout<<"\nENTER THE CAPACITY OF KNAPSACK"<<endl;
    cin>>m;
    cout<<"\nTHE MAXIMUM VALUE OF ITEMS THAT CAN BE PUT INTO KNAPSACK IS"<<knapsack(w , p , n , m);
    return 0;
}
