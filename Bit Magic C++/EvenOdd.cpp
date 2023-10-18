// A simple C++ program to
// check for even or odd
#include <iostream>
using namespace std;
bool isEven(int n) { return (n % 2 == 0); } // Returns true if n is
// even, else odd

int main()
{
    int n = 101;
    isEven(n) ? cout << "Even" : cout << "Odd";

    return 0;
}
