/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Oct 6, 2013
 Update:     Oct 8, 2014
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
           3. Keep a non-descending stack. O(n). if the vector height is not allowed to be changed.
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        return largestRectangleArea_1(height);
    }
    int largestRectangleArea_1(vector<int> &height) {
        int res = 0;
        int N = height.size();
        for (int i = 0; i < N; ++i) {
            if (i < N - 1 && height[i] <= height[i + 1]) {
                continue;
            }
            int minHeight = height[i];
            for (int j = i; j >= 0; --j) {
                minHeight = min(minHeight, height[j]);
                res = max(res, (i - j + 1) * minHeight);
            }
        }
        return res;
    }
    int largestRectangleArea_2(vector<int> &height) {
        height.push_back(0);
        int N = height.size();
        int res = 0, i = 0;
        stack<int> s;
        while (i < N) {
            if (s.empty() || height[i] >= height[s.top()]) {
                s.push(i++);
            } else {
                int idx = s.top(); s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                res = max(res, height[idx] * width);
            }
        }
        return res;
    }
    
    int largestRectangleArea_3(vector<int> &height) {
        int N = height.size();
        int res = 0, i = 0;
        stack<int> s;
        while(i < N) {
            if(s.empty() || height[s.top()] <= height[i]){
                s.push(i++);
            }else{
                int idx = s.top(); s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                res = max(res, height[idx] * width);
            }
        }
        while(!s.empty()){
            int idx = s.top(); s.pop();
            int width = s.empty() ? i : (i - s.top() - 1);
            res = max(res, height[idx] * width);
        }
        return res;
    }
};