#include <bits/stdc++.h>
using namespace std;
int get_max_area(vector<int> a)
{
    int size = a.size();
    int ans = 0;
    a.push_back(0); // end of array
    stack<int> st;  // used to store indices
    for (int i = 0; i < size + 1; i++)
    {
        while (!st.empty() && a[st.top()] > a[i])
        {
            // this is a potential rectangle
            int top = st.top();
            int height = a[top];
            st.pop();
            if (st.empty())
            {

                ans = max(ans, height * i);
            }
            else
            {
                int length = i - st.top() - 1;
                // cout << length << endl;
                ans = max(ans, height * length);
                cout << ans << endl;
            }
        }
        st.push(i);
    }

    return ans;
}
int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // brute force - O(n2)
    // int ans = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     int minHeight = INT_MAX;
    //     for (int j = i; j < n; j++)
    //     {
    //         minHeight = min(arr[j], minHeight);
    //         int length = j - i + 1;
    //         ans = max(ans, length * minHeight);
    //     }
    // cout << ans << endl;
    // }long long

    vector<int> a = {3, 4, 5, 6, 2};
    cout << get_max_area(a) << endl;

    return 0;
}
