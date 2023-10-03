#include <iostream>
#include <vector>

using namespace std;

/* Code Explanation

This code defines a class named "Solution" with a public member function evalRPN that evaluates Reverse Polish Notation (RPN) expressions provided as a vector of strings named "tokens". The function uses an unordered_map, which maps arithmetic operators (e.g., "+", "-", "*", "/") to corresponding lambda functions for performing arithmetic operations. A stack is employed to help with the evaluation: when a number is encountered in the tokens, it's pushed onto the stack; when an operator is encountered, two numbers are popped from the stack, the operation is performed, and the result is pushed back onto the stack. Once all tokens are processed, the result of the RPN expression is the top value on the stack.

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};