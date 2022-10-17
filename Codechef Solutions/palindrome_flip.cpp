#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    int count=0;
	    int ans=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='0'){
	           count++; 
	        }
	        else{
	            ans++;
	        }
	    }
	    if(count%2==0 || ans%2==0){
	        cout<<"Yes"<<endl;
	    }
	    else{
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}

     
