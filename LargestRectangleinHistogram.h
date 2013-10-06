/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 6, 2013
 Problem:    Largest Rectangle in Histogram
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_84
 Notes:
 Given n non-negative integers representing the histogram's bar height where the width of each 
 bar is 1, find the area of largest rectangle in the histogram.
 For example,
 Given height = [2,1,5,6,2,3],
 return 10.

 Solution: 1. Only calucate area when reaching local maximum value.
           2. Keep a non-descending stack. O(n).
*/

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleArea_2(height);
    }
    
    int largestRectangleArea_1(vector<int> &height) {
        int res = 0, N = height.size();
        for (int i = 0; i < N; ++i) {
            if (i < N-1 && height[i] <= height[i+1])
                continue;
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                res = max((i-j+1) * minHeight, res);
            }
        }
        return res;
    }
    
    int largestRectangleArea_2(vector<int> &height) {
        height.push_back(0);
        int res = 0, i = 0, N = height.size();
        stack<int> stk;
        while (i < N) 
        {
            if (stk.empty() || height[stk.top()] <= height[i])
                stk.push(i++);
            else {
                int index = stk.top(); stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                res = max(res, width * height[index]);
            }
        }
        return res;
    }
};
