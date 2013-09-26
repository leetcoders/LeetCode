/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 20, 2013
 Problem:    3Sum Closest
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_16
 Notes:
 Given an array S of n integers, find three integers in S such that the sum is closest to 
 a given number, target. Return the sum of the three integers. 
 You may assume that each input would have exactly one solution.
 For example, given array S = {-1 2 1 -4}, and target = 1.
 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 Solution: Similar to 3Sum, only taking O(n^2) time complexity.
 */

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int res = INT_MAX;
        sort(num.begin(), num.end());
        for (size_t i = 0; i < num.size(); ++i)
        {
            int l = i + 1, r = num.size() - 1;
            while (l < r)
            {
                int sum = num[i] + num[l] + num[r];
                if (res == INT_MAX || abs(sum - target) < abs(res - target))
                    res = sum;
                if (sum == target) return res;
                else if (sum < target) l++;
                else r--;
            }
        }
        return res;
    }
};