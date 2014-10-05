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

 Solution: Count the number of each bit.
*/

class Solution {
public:
    int singleNumber(int A[], int n) {
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
};
