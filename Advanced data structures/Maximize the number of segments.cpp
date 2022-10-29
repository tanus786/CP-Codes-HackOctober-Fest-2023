//C++ Code to find maximum number of cut segments
// Memoization DP

#include <bits/stdc++.h>
using namespace std;

//Function to find the maximum number of cuts.
int dp[10005];
	
int func(int l, int p, int q, int r)
{
	if(l==0)
	return 0;							 // Base Case
			
	if(dp[l]!=-1)							 // If already memoized
		return dp[l];
		
	int a(INT_MIN),b(INT_MIN),c(INT_MIN);		 // Intitialise a,b,& c with INT_MIN

	if(p<=l)									 // If Possible to make a cut of length p
		a=func(l-p,p,q,r);

	if(q<=l)									 // If possible to make a cut of length q
		b=func(l-q,p,q,r);

	if(r<=l)									 // If possible to make a cut of length r
		c=func(l-r,p,q,r);

	return dp[l]=1+max({a,b,c});				 // Memoize & return
		
}
	
int maximizeTheCuts(int l, int p, int q, int r)
{
	memset(dp,-1,sizeof(dp));				 // Set Lookup table to -1
	int ans=func(l,p,q,r);				 // Utility function call
		
	if(ans<0)
	return 0;					 // If returned answer is negative , that means cuts are not possible
	return ans;
}

int main()
{

int l,p,q,r;
cout<<"ENTER THE LENGTH OF THE ROD "<<endl;
cin>>l;

cout<<"ENTER THE VALUES OF p,q & r "<<endl;
cin>>p>>q>>r;

cout<<"THE MAXIMUM NUMBER OF SEGMENTS THAT CAN BE CUT OF LENGTH p,q & r FROM A ROD OF LENGTH l are "<<maximizeTheCuts(l,p,q,r)<<endl;
	return 0;
}
