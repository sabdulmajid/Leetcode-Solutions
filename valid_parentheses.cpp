#include <iostream>
#include <stack>

using namespace std;

/*
The function works by using a stack to track the open parentheses. When the function encounters an open parenthesis, it pushes it onto the stack. When the function encounters a closing parenthesis, it pops the top element off the stack and checks if it is the matching open parenthesis. If it is, the function continues. If it is not, the function returns false. The function returns true if the stack is empty at the end of the string.

Here is a more detailed explanation of the steps the function takes:

    1. The function creates a stack to track the open parentheses.
    2. The function iterates over the string, character by character.
    3. If the current character is an open parenthesis, the function pushes it onto the stack.
    4. If the current character is a closing parenthesis, the function pops the top element off the stack.
    5. If the top element of the stack is not the matching open parenthesis, the function returns false.
    6. If the function reaches the end of the string and the stack is empty, the function returns true.

Here are some examples of valid and invalid strings of parentheses:

Valid: "()"
Valid: "()[]{}"
Invalid: "()[]}"
Invalid: "(()"

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};