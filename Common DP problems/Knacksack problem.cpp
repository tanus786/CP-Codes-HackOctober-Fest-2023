// Problem : Given a set of items with weights and values, determine
//  the maximum value that can be 
// obtained by selecting items such that the 
// sum of the weights does not exceed a given capacity.

#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack Problem
int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();

    // Create a 2D array to store the maximum value
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Fill in the dp array
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    int maxVal = knapsack(weights, values, capacity);

    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
