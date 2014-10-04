/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 3, 2013
 Problem:    Single Number
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/single-number/
 Notes:
 Given an array of integers, every element appears twice except for one. 
 Find that single one.
 Your algorithm should have a linear runtime complexity. 
 Could you implement it without using extra memory?

 Solution: XOR.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n < 1) return 0;
        for (int i = 1; i < n; ++i)
            A[0] ^= A[i];
        return A[0];
    }
};
