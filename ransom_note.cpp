#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

This code defines a class Solution that contains a method canConstruct(ransomNote, magazine) to determine if it's possible to construct the ransomNote string using characters from the magazine string. The method uses an unordered_map called dictionary to keep track of character frequencies in the magazine. It first iterates through the magazine to populate the dictionary with character counts. Then, it iterates through the ransomNote, decrementing the character count in the dictionary for each character encountered. If the character is not found in the dictionary or its count becomes negative, the method returns false indicating that the ransomNote cannot be constructed. If the iteration completes successfully for all characters, it returns true, indicating that the ransomNote can be constructed from the characters in the magazine.

*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dictionary;

        // Iterate through the magazine and count characters
        for (char c : magazine) {
            if (dictionary.find(c) == dictionary.end()) {
                dictionary[c] = 1;
            } else {
                dictionary[c]++;
            }
        }

        // Iterate through the ransom note and check character counts
        for (char c : ransomNote) {
            if (dictionary.find(c) != dictionary.end() && dictionary[c] > 0) {
                dictionary[c]--;
            } else {
                return false;
            }
        }

        return true;
    }
};
