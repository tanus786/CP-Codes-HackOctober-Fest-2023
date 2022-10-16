#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tst;

    cin >> tst;

    while (tst--)
    {

        int lena, lenb;

        cin >> lena;

        int arra[lena];

        for (int cntr = 0; cntr < lena; cntr++)
        {
            cin >> arra[cntr];
        }

        cin >> lenb;
    set <int> s1;
        int input;

        for (int cntr = 0; cntr < lenb; cntr++)
        {
           cin>>input;

           s1.insert(input);
        }

        for (int cntr = 0; cntr < lena; cntr++)
        {
            if (s1.count(arra[cntr]))
            continue;
            
            else
                cout << arra[cntr] << " ";
        }

        cout << endl;
    }
    return 0;
}
