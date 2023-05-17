#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int it = 0; it < nums.size(); it++) {
            if (nums[it] == target) return it; 
        }
        return -1;
    }
};