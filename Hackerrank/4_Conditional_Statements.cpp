// Link: https://www.hackerrank.com/challenges/c-tutorial-conditional-if-else/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    if (n == 1)
    {
        cout << "one";
    }
    else if (n == 2)
    {
        cout << "two";
    }
    else if (n == 3)
    {
        cout << "three";
    }
    else if (n == 4)
    {
        cout << "four";
    }
    else if (n == 5)
    {
        cout << "five";
    }
    else if (n == 6)
    {
        cout << "six";
    }
    else if (n == 7)
    {
        cout << "seven";
    }
    else if (n == 8)
    {
        cout << "eight";
    }
    else if (n == 9)
    {
        cout << "nine";
    }
    else
    {
        cout << "Greater than 9";
    }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
