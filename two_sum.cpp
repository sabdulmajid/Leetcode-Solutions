#include <iostream>
#include <vector>

using namespace std;

/*
The function works by iterating over the array, pair-wise, and checking if the sum of the two numbers is equal to the target. If it is, the function returns the indices of the two numbers. If it is not, the function continues iterating. The function returns an empty vector if no two numbers in the array add up to the target.

Here is a more detailed explanation of the steps the function takes:

    1. The function creates a vector to store the indices of the two numbers.
    2. The function iterates over the array, pair-wise.
    3. For each pair of numbers, the function checks if the sum of the two numbers is equal to the target.
    4. If the sum of the two numbers is equal to the target, the function adds the indices of the two numbers to the vector.
    5. The function returns the vector.

*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        int size = nums.capacity();
        for (int i = 0; i < size - 1; i++) {
            for (int j = i+1; j < size; j++) {
                if (nums[i] + nums[j] == target) {
                    answer.push_back(i);
                    answer.push_back(j);
                    return answer;
                }
            }
        }
        return answer;
    }
};