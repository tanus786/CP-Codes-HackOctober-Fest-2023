#include <iostream>
using namespace std;

int main() {
    int num, originalNum, r, result = 0;
    cout << "Enter a three numbers: ";
    cin >> num;
    originalNum = num;

    while (originalNum != 0) {
    
        r = originalNum % 10;
        
        result += r * r * r;
        
        originalNum /= 10;
    }

    if (result == num)
        cout << num << " is an Armstrong number.";
    else
        cout << num << " is not an Armstrong number.";

    return 0;
}
