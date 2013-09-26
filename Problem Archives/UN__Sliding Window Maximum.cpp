/*
Usage:  Sliding Window Maximum
Author: Annie Kim
Date:   Aug 21, 2013
Problem Link:   http://leetcode.com/2011/01/sliding-window-maximum.html
*/

#include <iostream>
#include <deque>
using namespace std;

deque<int> dq;

void push_max(int val)
{
    while (!dq.empty() && val > dq.back())
        dq.pop_back();
    dq.push_back(val);
}

void maxSlidingWindow(int A[], int n, int w, int B[])
{
    for (int i = 0; i < w; ++i)
        push_max(A[i]);
    B[0] = dq.front();
    for (int i = 1; i <= n - w; ++i)
    {
        if (A[i-1] == dq.front())
            dq.pop_front();
        push_max(A[i+w-1]);
        B[i] = dq.front();
    }
}

int main()
{
    int A[] = {1, 3, -1,-3, 5, 3, 6, 7};
    int B[8];
    maxSlidingWindow(A, 8, 3, B);
    return 0;
}