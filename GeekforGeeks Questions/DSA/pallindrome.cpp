#include <bits/stdc++.h>
using namespace std;
//use recurssion
void pallindrome(string s, int i, int j)
{
    if (i >= j)
    {
        cout << "Pallindrome";
        return;
    }
    if (s[i] != s[j])
    {
        cout << "Not Pallindrome";
        return;
    }
    pallindrome(s, i + 1, j - 1);
}
int main(){
    string s;
    cin>>s;
    pallindrome(s,0,s.length()-1);
    return 0;
}