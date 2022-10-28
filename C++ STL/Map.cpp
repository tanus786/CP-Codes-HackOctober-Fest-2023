#include <iostream>
#include <map>

using namespace std;

int main ()
{
    map<string, int> mp;
    mp["Asia"] = 1; 
    mp["Europe"] = 2;
    mp["Australia"] = 3;
    mp["Antarctica"] = 4 ; 

    cout << "The roll number of Antarctica is: " << mp["Antarctica"] << endl;
    cout << "The roll number of Europe is: " << mp["Europe"] << endl;

    return 0;
}

