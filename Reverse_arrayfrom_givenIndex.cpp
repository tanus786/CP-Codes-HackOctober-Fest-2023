#include <iostream>
#include <vector>
using namespace std;

vector<int> reverse(vector<int> v,int m)
{
    int s = m+1;
    int e = v.size() - 1;
    while (s <= e)
    {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8};
    int index;
    cout<<"Enter the index number from where you want to reverse the array: ";
    cin>>index;
    vector<int> ans = reverse(arr,index);
    print(ans);
    return 0;
}
