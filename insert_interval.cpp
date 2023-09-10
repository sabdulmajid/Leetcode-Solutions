#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

This code is a function that takes a list of intervals and a new interval as input, and returns a list of intervals that includes the new interval without overlapping. The function does the following steps:

- It loops through the intervals until it finds one that ends after or at the same time as the new interval starts, and adds those intervals to the output list.
- It merges the new interval with any intervals that start before or at the same time as the new interval ends, by updating the new interval's start and end to be the minimum and maximum of both intervals, respectively.
- It adds the merged new interval to the output list.
- It adds the remaining intervals that start after the new interval ends to the output list.

*/


class Solution {
public:
   vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }                           

        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};