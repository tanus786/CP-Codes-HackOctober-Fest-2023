//C++ program to find the union of two arrays

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of first set: "<<endl;
    cin>>n;
    int m;
    cout<<"Enter the size of second set: "<<endl;
    cin>>m;
    int arr[n];
    cout<<"Enter the elements of first set: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int brr[m];
    cout<<"Enter the elements of second set: "<<endl;
    for(int i=0; i<m; i++){
        cin>>brr[i];
    }

    set<int> st;
    for(int i=0; i<n; i++)
        st.insert(arr[i]);

    for(int i=0; i<m; i++)
        st.insert(brr[i]);

    for (auto itr = st.begin(); itr != st.end(); itr++)
        cout << *itr << " ";
    
    return 0;
}
