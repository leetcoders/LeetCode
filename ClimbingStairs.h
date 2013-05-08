/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Problem:    Climbing Stairs
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_70
 Notes:
 You are climbing a stair case. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 Solution: Clime one step from last stair or clime 2 steps from the last last stair.
 */

class Solution {
public:
    int climbStairs(int n) {
        int last = 1;
        int lastlast = 1;
        for (int i = 2; i <= n; i++)
        {
            int step = last + lastlast;
            lastlast = last;
            last = step;
        }
        return last;
    }
};