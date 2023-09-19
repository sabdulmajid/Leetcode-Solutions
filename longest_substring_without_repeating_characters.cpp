#include <iostream>
#include <string>

using namespace std;

/* Code Explanation

The code defines a class named `Solution` with a public method `lengthOfLongestSubstring` that takes a string `s` as input and returns the length of the longest substring without repeating characters. The method uses a sliding window technique, represented by the variable `start`, to keep track of the starting index of the current substring without duplicates. A vector `dict` of size 256 is used to store the most recent index where each character appears in the string. As the loop iterates over the string, it updates `start` and `dict` accordingly and calculates the maximum length of such a substring encountered so far, stored in `maxLen`.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};