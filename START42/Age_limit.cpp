#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int T;
	int i=0;
	cin>>T;
	while(i<T)
	{
	    int X,Y,A;
	    cin>>X>>Y>>A;
	    if(A>=X&&A<Y)
	    {
	    
	        cout<<"YES"<<endl;
	    }
	    else
	    {
	        cout<<"NO"<<endl;
	    }
	    
	    i++;
	}
	return 0;
}
