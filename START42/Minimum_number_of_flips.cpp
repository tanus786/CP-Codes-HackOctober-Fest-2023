#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	   int sum=0;
	   int n;
	   cin>>n;
	   int a[n];
	   for(int i=0;i<n;i++){
	     cin>>a[i];
	   }
	   for(int i=0;i<n;i++){
	     sum=sum+a[i];
	   }
	   if(sum=='0'){
	     cout<<"0"<<endl;
	   }else if(sum%2==0){
	     cout<<abs(sum/2)<<endl;
	   }else{
	     cout<<"-1"<<endl;
	   }
	}
	return 0;
}
