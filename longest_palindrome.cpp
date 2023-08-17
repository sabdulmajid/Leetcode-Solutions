#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/* Code Explanation

This C++ code defines a class `Solution` that contains a method `longestPalindrome` which takes a string `s` as input and returns the length of the longest possible palindrome that can be formed using characters from the input string. It does so by iterating through the characters of the input string and maintaining a count of each character using an unordered map (`ump`). If the count of a character becomes odd, the `oddCount` is incremented; otherwise, it is decremented. The code then checks if there are more than one characters with an odd count (indicating an odd-length palindrome) and returns the length of the input string minus the excess odd counts plus one, if applicable. If there's at most one odd-count character or none at all, the code returns the length of the entire input string as the longest possible palindrome length.

*/

class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount = 0;
        unordered_map<char, int> ump;
        for(char ch : s) {
            ump[ch]++;
            if (ump[ch] % 2 == 1)
                oddCount++;
            else    
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
};