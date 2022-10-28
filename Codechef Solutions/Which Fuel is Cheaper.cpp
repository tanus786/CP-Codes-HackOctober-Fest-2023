//Which Fuel is Cheaper | CodeChef Solution
#include <iostream>
using namespace std;
int main() {
    int test;
    cin >> test;
    while(test--){
    int X, Y, A, B, K, petrol_price, diesel_price;
    cin >> X >> Y >> A >> B >> K;
    petrol_price = X + (A * K);
    diesel_price = Y + (B * K);
    if (petrol_price < diesel_price){
        cout << "PETROL" << endl;
    }
    else if (diesel_price < petrol_price){
        cout << "DIESEL" << endl;
    }
    else{
        cout << "SAME PRICE" << endl;
    }
    }
    return 0;
}
