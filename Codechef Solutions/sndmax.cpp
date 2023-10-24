//To find the second largest no. among three nos.
#include <iostream>
using namespace std;

int main() 
{
	int N,A1,A2,A3;
	
	cin>>N;
	
	while(N>0)
	{
	    int smax=0;
	    cin>>A1>>A2>>A3;
	    
	    if(A1>A2 && A1>A3)
	    {
	        if(A2>A3)
	            smax=A2;
	        else
	            smax=A3;
	    }
	    else if(A2>A3)
	    {
	        if(A1>A3)
	            smax=A1;
	        else
	            smax=A3;
	    }
	    else
	    {
	        if(A1>A2)
	            smax=A1;
	        else
	            smax=A2;
	    }
	    
	    cout<<smax<<endl;
	    N--;
	    
	}
	return 0;
}