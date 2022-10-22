#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void show(set<int> s)
{
    set<int>::iterator i;
    for (i = s.begin(); i != s.end(); i++)
    {
        cout << *i << "  ";   
    }
    cout << endl;
}

int main()
{
    set<int> s;
    cout<<"Enter number of elements: ";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    cout << "\n\nThe elements of the Set are: ";
    show(s);
    cout << "\n\n\n";

    return 0;
}
