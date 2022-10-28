#include <iostream>
using namespace std;

class math
{
    int number;
    float temp, sqr_root;

public:
    void sqrt()
    {
        cout << "Enter the number whose square root you want to find: ";
        cin >> number;
        sqr_root = number / 2;
        temp = 0;
        while (sqr_root != temp)
        {
            temp = sqr_root;
            sqr_root = (number / temp + temp) / 2;
        }
        cout << "The square root of " << number << " is " << sqr_root << endl << endl;
    }
};

int main()
{
    int ch;
    math m;
    while (1)
    {   
        cout << "Menu:" << endl;
        cout << "     1. Square root of a number" << endl;
        cout << "     2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            m.sqrt();
            break;
        case 2:
            exit(0);
        default:
            cout << "Invalid choice" << endl << endl;
        }
    }
    return 0;
}
