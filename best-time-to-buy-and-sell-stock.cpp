#include <iostream>
#include <vector>

using namespace std;


/*

The function works by first creating a vector to store the maximum price of the stock on each day. The function then iterates over the vector, starting from the end, and calculates the profit that can be made by buying the stock on the current day and selling it on the next day. The function then keeps track of the maximum profit that has been found so far. The function returns the maximum profit that has been found.

Here is a more detailed explanation of the steps the function takes:

1. The function creates a vector to store the maximum price of the stock on each day.
2. The function iterates over the vector, starting from the end.
3. For each day, the function calculates the profit that can be made by buying the stock on the current day and selling it on the next day.
4. The function keeps track of the maximum profit that has been found so far.
5. The function returns the maximum profit that has been found.

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxPrices(n, 0);
        maxPrices[n-1] = prices[n-1];
        
        for(int i=n-2; i>=0; i--){
            maxPrices[i] = max(maxPrices[i+1], prices[i]); 
        }

        int maxProfit = 0;
        
        for(int i=0; i<n; i++){
            maxProfit = max(maxProfit, maxPrices[i] - prices[i]); 
        }

        return maxProfit;
    }
};