#include <iostream>
#include <string>

using namespace std;

/*

The function works by first checking each character in the string to see if it is alphanumeric. If a character is not alphanumeric, it is skipped. Otherwise, the character is converted to lowercase and compared to the character at the opposite end of the string. If the characters are not equal, the function returns false. Otherwise, the function continues to the next character.

If the function reaches the end of the string without returning false, it returns true. This means that the string is a palindrome.

*/

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