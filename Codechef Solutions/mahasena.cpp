//To check for the no. of soldiers holding even no. of weapons and
//check the readiness for battle
#include <iostream>
using namespace std;

int main() 
{
	int N,A;
	int i=0,j=0;
	
	cin>>N;
	
	while(N>0)
	{  
	    cin>>A;
	    
	    if(A%2==0)
	        i++;
	        
	    else
	        j++;
	        
	    N--;
	}
	
	if(i>j)
	    cout<<"READY FOR BATTLE"<<endl;
	    
	else
	    cout<<"NOT READY"<<endl;
	    
	return 0;
}