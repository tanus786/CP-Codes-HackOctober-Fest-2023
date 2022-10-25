#include <iostream>
using namespace std;

int main() {
	// your code goes here'
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string a;
	    cin>>a;
	    int cnt=0;
	    //check for first element
	    
	    if(a[0]=='1')
	        cnt++;
	    for(int i=1;i<n-2;i++)
	    {
	        if(a[i-1]=='0' && a[i]=='1')
	            cnt++;
	    }
	    //check for last element
	    if((a[n-2]=='1' && a[n-3]=='0') || a[n-2]=='0')
	        cnt++;
	    if(n==2)
	        cnt=1;
	   cout<<cnt<<endl;
	}
	return 0;
}
