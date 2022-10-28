//c++ program to check whether we can remove a character to equalize the frequency of each character or not
#include<bits/stdc++.h>
using namespace std;

bool checkFrequency(string s) {
        map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        vector<int> v;
        for(auto it: mp)
            v.push_back(it.second);
        
        for(int i=0; i<v.size(); i++){
            v[i]=v[i]-1;
            if(v[i]==0){
                set<int> temp(v.begin(), v.end());
                if(temp.size()-1==1)
                    return true;
            }
            
            else{
                set<int> st(v.begin(), v.end());
                if(st.size()==1)
                    return true;
            }
            v[i]=v[i]+1;
        }
        return false;
}
    
int main(){
    string s;
    cout<<"Enter a string: "<<endl;
    cin>>s;
    
    bool ans=checkFrequency(s);
    if(ans)
        cout<<"Yes";
    
    else
        cout<<"No";
    return 0;
}
