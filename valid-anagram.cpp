#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

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