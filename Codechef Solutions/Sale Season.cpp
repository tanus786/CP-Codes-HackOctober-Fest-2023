 #include <iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    double sum=0;
	    for(int i=1;i<=n;i++){
	        double p,x,d;
	        cin>>p>>x>>d;
	        double dis=double(d)/100;
	        double finalp=p+(p*dis);
	        double finalfp=finalp-(finalp*dis);
	        double loss=x*(p-finalfp);
	        sum+=loss;
	    }
	    cout<<fixed<<sum<<endl;
	}
	return 0;
}
