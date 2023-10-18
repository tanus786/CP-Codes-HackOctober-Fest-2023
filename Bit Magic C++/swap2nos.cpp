// C++ code to swap using XOR
#include<iostream>
using namespace std;

int main()
{
    int x = 10, y = 5;
    x = x ^ y; // x now becomes 15 (1111)
    y = x ^ y; // y becomes 10 (1010)
    x = x ^ y; // x becomes 5 (0101)
    cout << "After Swapping: x =" << x << ", y=" << y;
    return 0;
}

