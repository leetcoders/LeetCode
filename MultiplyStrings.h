/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Problem:    Multiply Strings
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_43
 Notes:
 Given two numbers represented as strings, return multiplication of the numbers as a string.
 Note: The numbers can be arbitrarily large and are non-negative.

 Solution: Just like what we do when multiplying integers.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        int m = num1.size(), n = num2.size();
        int i, sum = 0, carry = 0;
        for (i = 0; i < m + n - 1 || carry > 0; ++i)
        {
            sum = carry;
            for (int j = max(i - n + 1, 0); j <= min(m - 1, i); ++j)
                sum += (num1[m-j-1]-'0') * (num2[n-(i-j)-1]-'0');
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
        }
        while (i > 1 && res[i-1] == '0')
            i--;
        res.resize(i);
        reverse(res.begin(), res.end());
        return res;
    }
};