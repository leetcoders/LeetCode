/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Gray Code
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_89
 Notes:
 The gray code is a binary numeral system where two successive values differ in only one bit.
 Given a non-negative integer n representing the total number of bits in the code, print the 
 sequence of gray code. A gray code sequence must begin with 0.
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 00 - 0
 01 - 1
 11 - 3
 10 - 2
 Note:
 For a given n, a gray code sequence is not uniquely defined.
 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 Solution: Refer to http://en.wikipedia.org/wiki/Gray_code.
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n, 0);
        for (int i = 0; i < 1 << n; ++i)
            result[i] = (i >> 1) ^ i;
        return result;
    }
};
