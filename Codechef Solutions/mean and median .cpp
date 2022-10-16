#include <iostream>
using namespace std;

int main()
{
    int tst;

    cin >> tst;

    while (tst--)
    {
        int x, y;

        cin >> x >> y;

        int num = (std::rand() % ((y + 5) - (3 * y) + 1));

        cout << num;

        cout << ((3 * x) - y) - num
             << " " << y << " " << num << endl;
    }
    return 0;
}
