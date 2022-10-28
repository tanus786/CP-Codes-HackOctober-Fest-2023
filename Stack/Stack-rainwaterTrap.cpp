#include <bits/stdc++.h>
using namespace std;

void trapRainWater(vector<int> &heights)
{
    int size = heights.size();
    int prefixMax[size], suffixMax[size];
    int waterTrapped = 0, total[size];
    prefixMax[0] = heights[0];
    for (int i = 1; i < size; i++)
    {
        prefixMax[i] = max(prefixMax[i - 1], heights[i]);
    }
    int secondLast = size - 2;
    suffixMax[size - 1] = heights[size - 1];
    for (int i = secondLast; i >= 0; i--)
    {
        suffixMax[i] = max(suffixMax[i + 1], heights[i]);
    }

    for (int i = 0; i < size; i++)
    {
        total[i] = min(prefixMax[i], suffixMax[i]) - heights[i];
    }

    for (int i = 0; i < size; i++)
    {
        waterTrapped += total[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << total[i] << " ";
    }
    cout << endl;

    cout << waterTrapped << endl;
}
int main()
{
    vector<int> heights = {3, 0, 0, 2, 0, 4};
    trapRainWater(heights);
    return 0;
}
