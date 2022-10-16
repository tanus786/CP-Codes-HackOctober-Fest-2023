#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int t;
	cin>>t;
	while(t--){
	    long long int n,k;
	    cin>>n>>k;
	    if(k==1){
	        if(n%2==0)
	        cout<<"even"<<endl;
	        else
	        cout<<"odd"<<endl;
	    }
	    else if(k==2)
	    cout<<"odd"<<endl;
	    else
	    cout<<"even"<<endl;
	}
	return 0;
}
