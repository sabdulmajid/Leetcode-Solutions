#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* Code Explanation

This is a C++ code that checks if a given vector of integers `nums` contains any duplicates. The function `containsDuplicate` returns a boolean value of `true` if there are any duplicates, and `false` otherwise. The function uses an unordered map `seen` to keep track of the number of times each integer appears in the vector. It then iterates through the vector, incrementing the count for each integer in the map. If the count for an integer is greater than or equal to 1, it means that the integer has already appeared in the vector, so the function returns `true`. Otherwise, it continues iterating through the vector. This approach has a time complexity of O(n), where n is the length of the input vector.

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num : nums) {
            if (seen[num] >= 1)
                return true;
            seen[num]++;
        }
        return false;
    }
};