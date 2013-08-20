/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Update:     Aug 20, 2013
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
        int N = num1.size(), M = num2.size();
        string res(N+M, '0');
        for (int i = N - 1; i >= 0; --i)
        {
            int carry = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                int sum = carry + (res[i+j+1] - '0') + 
                          (num1[i] - '0') * (num2[j] - '0');
                res[i+j+1] = sum % 10 + '0';
                carry = sum / 10;
            }
            res[i] += carry;
        }
        while (res.size() > 1 && res[0] == '0')
            res.erase(res.begin());
        return res;
    }
};
