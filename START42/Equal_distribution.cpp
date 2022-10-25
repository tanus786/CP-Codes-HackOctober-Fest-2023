#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,k,x,c;
	cin>>t;
	while(t--)
	{
	    cin>>k>>x;
	    c=k+x;
	    if(c%2==0)
	    {
	    cout<<"yes"<<endl;
	    }
	    else
	    {
	        cout<<"no"<<endl;
	    }
	}
	return 0;
}
