/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Container With Most Water
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_11
 Notes:
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 Note: You may not slant the container.

 Solution: Search from both sides. When searching towards center, the new height 
           cannot be less than the current minimum height.
 */

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) 
        {
            int h = min(height[l], height[r]);
            res = max(res, h * (r-l));
            if (height[l] <= height[r]) {
                l++;
                while (height[l] < h) l++;
            } else {
                r--;
                while (height[r] < h) r--;
            }
        }
        return res;
    }
};