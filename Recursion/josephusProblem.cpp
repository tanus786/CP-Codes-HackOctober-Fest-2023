#include <bits/stdc++.h>
using namespace std;
void kill(int k, vector<int> &people, int sword, int &ans)
{
    int size = people.size();
    if (size == 1)
    {
        ans = people[0];
        return;
    }
    sword = (sword + k) % size;
    people.erase(people.begin() + sword);
    kill(k, people, sword, ans);
}
int main()
{

    int n;
    cin >> n;
    int k;
    cin >> k;
    k--;
    vector<int> people;
    for (int i = 1; i <= n; i++)
    {
        people.push_back(i);
    }
    int sword = 0;
    int ans = -1;
    kill(k, people, sword, ans);
    cout << "survior: " << ans;
    return 0;
}
