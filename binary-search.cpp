#include <iostream>
#include <vector>

using namespace std;

/*

The search() method iterates through the vector and compares each element to the target integer. If the target integer is found, the method returns the index of the element. If the target integer is not found, the method returns -1.

The search() method can be used to find the index of a target integer in a vector. The method works by iterating through the vector and comparing each element to the target integer. If the target integer is found, the method returns the index of the element. If the target integer is not found, the method returns -1.

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int it = 0; it < nums.size(); it++) {
            if (nums[it] == target) return it; 
        }
        return -1;
    }
};