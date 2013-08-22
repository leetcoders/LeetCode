/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Aug 22, 2013
 Problem:    Container With Most Water
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_11
 Notes:
 Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 Note: You may not slant the container.

 Solution: From both sides to the center.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int res = 0;
        int l = 0, r = height.size()-1;
        while (l < r)
        {
            if (height[l] <= height[r])
            {
                res = max(res, (r-l) * height[l]);
                l++;
            }
            else
            {
                res = max(res, (r-l) * height[r]);
                r--;
            }
        }
        return res;
    }
};
