#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The code you provided is a C++ implementation of the **maximum subarray problem**. The problem is to find the contiguous subarray within a one-dimensional array of numbers that has the largest sum. The code defines a function `maxSubArray` that takes a vector of integers `nums` as input and returns an integer. The function uses two variables, `sum` and `smax`, to keep track of the current sum and maximum sum seen so far, respectively. It iterates over each element in the input vector and updates the variables accordingly. If the current sum becomes negative, it resets to zero because any negative sum will only decrease the maximum sum. Finally, it returns the maximum sum seen so far. This implementation uses **Kadane's algorithm**, which has a time complexity of O(n) and space complexity of O(1).

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }
};