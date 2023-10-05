// Problem :  You are given an array of coin denominations and a total amount to make change for.
//  Write a function to determine the number of ways to make the change using the given denominations. 
// You can use each coin denomination an unlimited number of times.

#include <iostream>
#include <vector>
using namespace std;

// Function to count the number of ways to make change for a given amount
int coinChangeWays(vector<int>& coins, int amount) {
    // Create an array to store the number of ways for each amount from 0 to the target amount
    vector<int> dp(amount + 1, 0);

    // There's one way to make change for 0, which is to use no coins.
    dp[0] = 1;

    // Iterate through each coin denomination
    for (int coin : coins) {
        // Update dp array for each amount from the coin value to the target amount
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int ways = coinChangeWays(coins, amount);

    cout << "Number of ways to make change for " << amount << " is: " << ways << endl;

    return 0;
}
