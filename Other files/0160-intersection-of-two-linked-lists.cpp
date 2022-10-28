#include <bits/stdc++.h>  
using namespace std;  
void find_greatest(int a, int b, int c, int d)  
{  
    int x = max(a, max(b, max(c, d)));  
    if (x == a)  
        cout << "a is greatest";  
    if (x == b)  
        cout << "b is greatest";  
    if (x == c)  
        cout << "c is greatest";  
    if (x == d)  
        cout << "d is greatest";  
}  
  
int main()  
{  
    int a = 10, b = 50, c = 20, d = 25;  
    cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d;  
    cout << "\n";  
    find_greatest(a, b, c, d);  
    a = 35, b = 50, c = 99, d = 2;  
    cout << "\n";  
    cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d;  
    cout << "\n";  
    find_greatest(a, b, c, d);  
  
    return 0;  
}  
