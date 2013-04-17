/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Problem:    Add Binary
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_67
 Notes:
 Given two binary strings, return their sum (also a binary string).
 For example,
 a = "11"
 b = "1"
 Return "100".

 Solution: '1'-'0' = 1.
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while (true)
        {
            int aa = 0, bb = 0;
            if (i >= 0) aa = a[i] - '0';
            if (j >= 0) bb = b[j] - '0';
            res.push_back(char((aa + bb + carry) % 2 + '0'));
            carry = (aa + bb + carry) / 2;
            i--; j--;
            if (i < 0 && j < 0) break;
        }
        if (carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};