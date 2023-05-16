#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAlphanumeric(char ch)    {
        if(ch >= 'a' && ch <= 'z') return true;
        if(ch >= 'A' && ch <= 'Z') return true;
        if(ch >= '0' && ch <= '9') return true;
        return false;
    }

    bool isPalindrome(string s) {
        int i=0;
        int j = s.length()-1;
        while(i != j) {
            if (!isAlphanumeric(s[i])) i++;  
            else if (!isAlphanumeric(s[j])) j--;
            else if (tolower(s[i]) != tolower(s[j])) return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};