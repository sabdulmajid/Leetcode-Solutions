#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/* Code Explanation

This is a C++ code that defines a class MyQueue that implements a queue using two stacks. The class has four methods: push, pop, peek, and empty.

1. The push method adds an element to the queue by pushing it onto the inp stack.

2. The pop method removes and returns the first element in the queue by popping elements from the out stack. If the out stack is empty, it first transfers all elements from the inp stack to the out stack.

3. The peek method returns the first element in the queue without removing it. If the out stack is empty, it first transfers all elements from the inp stack to the out stack.

4. The empty method returns a boolean value indicating whether or not the queue is empty.

This implementation of a queue using two stacks is known as a two-stack queue or a queue with amortized constant time complexity. The push and pop methods have an amortized time complexity of O(1), while the peek and empty methods have a time complexity of O(1).

*/

class MyQueue {
    stack<int> inp, out;
public:
    MyQueue() {}
    
    void push(int x) {
        inp.push(x);
    }
    
    int pop() {
        if (out.empty()) {
            while (!inp.empty()) {
                out.push(inp.top());
                inp.pop();
            }
        }
        int temp = out.top();
        out.pop();
        return temp;
    }
    
    int peek() {
        if (out.empty()) {
            while (!inp.empty()) {
                out.push(inp.top());
                inp.pop();
            }
        }
        return out.top();
    }
    
    bool empty() {
        return (inp.empty() && out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */