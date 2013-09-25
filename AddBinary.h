/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Sep 25, 2013
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
        int N = a.size(), M = b.size(), K = max(N, M);
        string res(K, ' ');
        int carry = 0;
        int i = N-1, j = M-1, k = K-1;
        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 2;
            res[k--] = sum % 2 + '0';
        }
        if (carry == 1)
            res.insert(res.begin(), '1');
        return res;
    }
};