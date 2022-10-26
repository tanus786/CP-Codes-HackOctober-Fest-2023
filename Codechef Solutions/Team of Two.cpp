#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int solu(vector<int>a,vector<int>b) {
    set<int>st;
    for(int i=0;i<a.size();i++) {
        st.insert(a[i]);
    }
    for(int i=0;i<b.size();i++) {
        st.insert(b[i]);
    }
    int s=0;
    s = st.size();
    return s ;
}
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<vector<int>>vec_studen;
	    while(n--) {
	        vector<int>v;
	        int size;
	        cin>>size;
	        for(int i=0;i<size;i++) {
	            int q;
	            cin>>q;
	            v.push_back(q);
	        }
	        vec_studen.push_back(v);
	    }
	    //vector<int>ans;
	    bool flag = false;
	    for(auto i=vec_studen.begin();i!=vec_studen.end();i++) {
	        for(auto j=vec_studen.begin();j!=vec_studen.end();j++) {
	           if (solu(*i,*j)==5) {
	               flag=true;
	               break;
	           }
	        }
	    }
	    //cout<<*max_element(ans.begin(),ans.end());
	    //sort(ans.begin(),ans.end());
	    if(flag == true){
	        cout<<"YES"<<endl;
	    }
	    else {
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
       
