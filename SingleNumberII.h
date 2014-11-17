/*
 Author:     King, higuige@gmail.com : Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 5, 2013
 Update:     Oct 5, 2014
 Problem:    Single Number II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/single-number-ii/
 Notes:
 Given an array of integers, every element appears three times except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. Could you implement it 
 without using extra memory?

 Solution: 1. Count the number of each bit.
        2. We can improve this based on the previous solution using three bitmask variables.
        3. An excellent answer by @ranmocy in LeetCode Discuss:
        https://oj.leetcode.com/discuss/857/constant-space-solution?show=2542#a2542
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        int count[32]={0};
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((A[j]>>i)&1) {
                    ++count[i];
                }
            }
            res|= ((count[i]%3)<<i);
        }
        return res;
    }
    int singleNumber_2(int A[], int n) {
        int twice = 0;
        int once = 0;
        for (int i = 0; i < n; ++i) {
            twice |= once & A[i];
            once ^= A[i];
            int notthree = ~ (twice & once);
            twice = twice & notthree;
            once  = once & notthree;
        }
        return once;
    }
    int singleNumber_3(int A[], int n) {
        if (A == NULL) return 0;
        int x0 = ~0, x1 = 0, x2 = 0, t;
        for (int i = 0; i < n; ++i) {
            t = x2;
            x2 = (x1 & A[i]) | (x2 & ~A[i]);
            x1 = (x0 & A[i]) | (x1 & ~A[i]);
            x0 = (t & A[i]) | (x0 & ~A[i]);
        }
        return x1;
    }
};
