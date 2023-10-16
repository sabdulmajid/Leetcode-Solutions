#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The Solution class contains a function named coinChange, which determines the minimum number of coins required to make up a given amount n using the coin denominations provided in the coins vector. The solution employs dynamic programming for efficiency. A dp array is used where dp[i] represents the minimum number of coins required to get the amount i. The array is initialized such that dp[0] is 0 (because zero coins are needed for amount 0) and all other values are set to INT_MAX (representing an unreachable amount). The coins are sorted for efficiency. For each amount i, the function iterates through the coins and checks if subtracting the current coin's value from i results in a valid index of dp. If it does, and the amount i-c was reachable (i.e., dp[i-c] is not INT_MAX), the function updates dp[i] with the minimum of its current value and 1 + dp[i-c]. After populating the dp array, if dp[n] is INT_MAX, the function returns -1 (indicating that amount n can't be made up using the given coin denominations); otherwise, it returns the value at dp[n], which is the minimum number of coins required.

*/

class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        // creating the base dp array, with first value set to 0
        int dp[++n];
        dp[0] = 0;
        // more convenient to have the coins sorted
        sort(begin(coins), end(coins));
        // populating our dp array
        for (int i = 1; i < n; i++) {
            // setting dp[0] base value to 1, 0 for all the rest
            dp[i] = INT_MAX;
            for (int c: coins) {
                if (i - c < 0) break;
                // if it was a previously not reached cell, we do not add use it
                if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[--n] == INT_MAX ? -1 : dp[n];
    }
};