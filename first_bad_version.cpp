#include <iostream>
#include <vector>


using namespace std;

/* Code Explanation

This code defines a class Solution that contains a method firstBadVersion(n) which uses binary search to efficiently find the first occurrence of a "bad version" among a range of versions from 1 to n. The method iteratively narrows down the search range by dividing it in half until it finds the first bad version. It uses the isBadVersion() API to check if a given version is bad or not. The algorithm maintains two pointers, low and high, and updates them based on the result of isBadVersion() to efficiently find the first bad version in logarithmic time.

*/

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n == 1) return n;

        int low = 1;
        int high = n;
        
        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)) high = mid;
            else low = mid + 1;
        }
        return low;

    }
};