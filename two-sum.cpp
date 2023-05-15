#include <iostream>
#include <vector>
using namespace std;

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