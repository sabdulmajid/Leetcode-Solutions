#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/* Code Explanation

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