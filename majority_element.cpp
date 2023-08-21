#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/* Code Explanation

This C++ code defines a class `Solution` that contains a method `majorityElement` for finding the majority element in a given vector of integers `nums`. The majority element is the element that appears more than half of the total number of elements in the vector. The method uses an unordered map `counter` to keep track of the count of each distinct element in the input vector. It iterates through the vector, incrementing the count of each element in the map. If at any point the count of an element becomes greater than half the size of the input vector, the method returns that element as the majority element. If no majority element is found, it returns 0.

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (++counter[num] > nums.size() / 2) {
                return num;
            }
        }
        return 0;
    }
};