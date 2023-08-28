#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* Code Explanation

This C++ code defines a class `Solution` that contains a method `addBinary` for adding two binary strings represented as input strings `a` and `b`. The method simulates binary addition by iterating through the input strings from their least significant digits to the most significant digits, while also considering a carry value. It adds corresponding digits from both strings along with the carry, updates the carry for the next iteration, and appends the sum of digits to the result string `ans`. The carry is then divided by 2 to prepare for the next addition. After processing both input strings, the result string is reversed to obtain the correct order of binary digits. Finally, the method returns the result as a binary string sum of the input strings.

*/

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};