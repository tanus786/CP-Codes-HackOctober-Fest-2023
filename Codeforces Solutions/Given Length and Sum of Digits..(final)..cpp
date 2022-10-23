#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int m,s,i;
	cin>>m>>s;
	char max[m],min[m];
	int sum=s;
	if((s>0&&s<=(9*m))||(s==0&&m==1))
		{
			for(i=0;i<m;i++)
			{
				if(s>=9)
					max[i]='9';
				else
					max[i]=s+'0';
				s=s-((int)max[i]-'0');
			}
			for(i=0;i<m;i++)
				min[i]=max[m-i-1];
			if(min[0]=='0')
			{
				for(i=1;i<m;i++)
				{
					if(min[i]!='0')
					{
						min[i]=min[i]-('1'-'0')	;
						min[0]='1';
						break;
					}	
				}
			}
			for(i=0;i<m;i++)
				cout<<min[i];
					cout<<" ";
			for(i=0;i<m;i++)
				cout<<max[i];
		}
	else
		cout<<"-1"<<" "<<"-1";
}
