// C++ Program to swap two numbers without using third variable
#include <iostream>

using namespace std;

int main()
{
    int a,b;
    cout<<"Enter 2 numbers: ";
    cin>>a>>b;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    a = a * b;
    b = a / b;
    a = a / b;
    cout<<"a = "<<a<<" b = "<<b<<endl;
    return 0;
}
