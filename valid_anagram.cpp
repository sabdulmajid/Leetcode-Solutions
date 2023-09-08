#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


/*

The function first checks if the two strings have the same length. If they do not, then the function returns false. If they do have the same length, then the function creates two unordered maps. An unordered map is a data structure that maps keys to values. In this case, the keys are the characters in the strings and the values are the number of times each character appears in the string.

The function then iterates over the first string and increments the count of each character in the first unordered map. It then iterates over the second string and increments the count of each character in the second unordered map.

Finally, the function checks if the two unordered maps are equal. If they are, then the function returns true. If they are not, then the function returns false.

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> m1, m2;
        for (char c : s) m1[c]++;
        for (char c : t) m2[c]++;

        return m1 == m2;
    }
};