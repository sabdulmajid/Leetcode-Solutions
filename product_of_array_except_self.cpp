#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The Solution class has a function productExceptSelf that calculates, for each position in the input nums vector, the product of all numbers in the vector except the number at that position. The function first populates the output vector with products of all numbers to the left of each index by iterating from left to right. Then, it adjusts these values with products of numbers to the right of each index by iterating from right to left using a right variable to accumulate the right-side products. The result is a vector where each entry gives the product of all numbers in the original vector except for the number at the corresponding position.

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i=1; i<n; i++){
            output[i] = output[i-1] * nums[i-1];
        }
        int right = 1;
        for(int i=n-1; i>=0; i--){
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};