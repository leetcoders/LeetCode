/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 13, 2014
 Problem:    Factorial Trailing Zeroes
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/factorial-trailing-zeroes/
 Notes:
 Given an integer n, return the number of trailing zeroes in n!.

 Note: Your solution should be in logarithmic time complexity.

 Solution: ...
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};