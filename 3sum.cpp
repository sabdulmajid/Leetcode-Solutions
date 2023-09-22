#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

The code defines a class named Solution with a public method threeSum. This method takes a vector of integers nums as input and returns all unique triplets in the array which sum up to zero. Firstly, the array is sorted. Then, by using a fixed element and two pointers (one starting right after the fixed element and the other at the end of the array), the method tries to find pairs whose sum with the fixed element equals zero. If the sum is less than zero, the left pointer (low) moves to the right; if it's greater, the right pointer (high) moves to the left. When a valid triplet is found, it's added to the output vector. To avoid duplicate results, both pointers skip over any subsequent duplicate values. Similarly, the outer loop skips over duplicates of the fixed element to further ensure uniqueness of the results.

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        for(int i=0; i<n-1; i++){
            int low = i+1, high = n-1;
            while(low < high){
                if(nums[i] + nums[low] + nums[high] < 0){
                    low++;
                }
                else if(nums[i] + nums[low] + nums[high] > 0){
                    high--;
                }
                else{
                    output.push_back({nums[i], nums[low], nums[high]});
                    int tempIndex1 = low, tempIndex2 = high;
                    while(low < high && nums[low] == nums[tempIndex1]) low++;
                    while(low < high && nums[high] == nums[tempIndex2]) high--;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};