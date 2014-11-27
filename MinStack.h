/*
 Author:     King, higuige@gmail.com
 Date:       Nov 14, 2014
 Problem:    Min Stack 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/min-stack/
 Notes:
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
public:
    void push(int x) {
        elements.push(x);
        if (minstk.empty() || x <= minstk.top()) {
            minstk.push(x);
        }
    }

    void pop() {
        if (elements.empty()) { 
            return;
        }
        if (elements.top() == minstk.top()) {
            minstk.pop();
        }
        elements.pop();
    }

    int top() {
        return elements.top();
    }

    int getMin() {
        return minstk.top();
    }
private:
    stack<int> elements;
    stack<int> minstk;
};
