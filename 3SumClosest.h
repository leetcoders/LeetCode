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

 Solution: Similar to 3Sum, taking O(n^2) time complexity.
 */

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int N = num.size();
        if (N < 3) return 0;
        int res = num[0] + num[1] + num[2];
        sort(num.begin(), num.end());
        for (int i = 0; i < N-2; ++i)
        {
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                int threesum = num[i] + num[l] + num[r];
                if (threesum == target) return target;
                else if (threesum < target) ++l;
                else --r;
                if (abs(threesum - target) < abs(res - target))
                    res = threesum;
            }
        }
        return res;
    }
};
