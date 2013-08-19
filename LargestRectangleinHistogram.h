/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Aug 20, 2013
 Problem:    Largest Rectangle in Histogram
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_84
 Notes:
 Given n non-negative integers representing the histogram's bar height where the width of each 
 bar is 1, find the area of largest rectangle in the histogram.
 For example,
 Given height = [2,1,5,6,2,3],
 return 10.

 Solution: Keep a non-descending stack. 
 Example: {2, 1, 2}
 1. push an additional 0 into the vector {2, 1, 2, 0}.
 2. {2}: stack = {2}, res = 0.
 3. {1}: popup 2, res = 2; push 1 instead, stack = {1}; push 1, stack = {1, 1}.
 4. {2}: stack = {1, 1, 2}, res = 0.
 5. {0}: popup 2, res = 2; 
         popup 1, res = 2; 
         popup 1, res = 3.
 */

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> stk;
        height.push_back(0);
        int res = 0, N = height.size();
        for (int i = 0; i < N; ++i)
        {
            int count = 0;
            while (!stk.empty() && stk.top() > height[i])
            {
                count++;
                res = max(res, count * stk.top());
                stk.pop();
            }
            while (count--)
                stk.push(height[i]);

            stk.push(height[i]);
        }
        return res;
    }
};