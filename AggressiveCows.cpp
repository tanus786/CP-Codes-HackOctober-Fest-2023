#include <bits/stdc++.h>
using namespace std;

int N,C;

int check(int num,int stalls[])
{
	int cows=1,position=stalls[0];
	for (int i=1; i<N; i++)
	{
		if (stalls[i]-position>=num)
		{
			position=stalls[i];
			cows++;
			if (cows==C)
				return 1;
		}
	}
	return 0;
}

int binarySearch(int stalls[])
{
	int start=0,end=stalls[N-1],max=-1;
	while (end>start)
	{
		int mid=(start+end)/2;
		if (check(mid,stalls)==1)
		{
			if (mid>max)
				max=mid;
			start=mid+1;
		}
		else
			end=mid;
	}
	return max;
}

int main()
{
	int t;
	cin>>t;

	while (t--)
	{
		cin>>N>>C;
		
		int stalls[N];
		
		for (int i=0; i<N; i++)
			cin>>stalls[i];
		
		sort(stalls,stalls+N);
		
		int k=binarySearch(stalls);
		
		cout<<k;
	}
	return 0;
}
