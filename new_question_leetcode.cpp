#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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
        
    }
    
    bool empty() {
        
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