#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a{1, 2, 3, 4, 5};
    vector<int> b{3, 2, 6, 7, 1};
    set<int> s;
    for(int i=0; i<a.size(); i++){
        s.insert(a[i]);
    }
    for(int i=0; i<b.size(); i++){
        s.insert(b[i]);
    }
    
    cout<<"Union of two arrays: "<<endl;
    for(auto it: s)
        cout<<it<<" ";

    return 0;
}
