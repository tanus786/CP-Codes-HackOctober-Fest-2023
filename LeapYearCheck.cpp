#include <iostream>
using namespace std;

int main() {
  int year;
  cout << "Please enter a year: ";
  cin >> year;
  // leap year if perfectly divisible by 400
  if (year % 400 == 0) {
    cout << year << " is a leap year.";
  }
  
  // not a leap year if divisible by 100
  else if (year % 100 == 0) {
    cout << year << " is not a leap year.";
  }
  
  // leap year if not divisible by 100
  else if (year % 4 == 0) {
    cout << year << " - is leap year.";
  }
  // all other years are not leap years
  else {
    cout << year << " - is not leap year.";
  }

  return 0;
}
