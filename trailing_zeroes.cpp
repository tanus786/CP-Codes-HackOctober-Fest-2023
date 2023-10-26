#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long count_five =0;
    long long num = n;
    while(num >= 5){
        num = num/5;
        count_five+= num;
    }

    cout << count_five;
}
