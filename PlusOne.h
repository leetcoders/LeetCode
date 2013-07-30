/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 30, 2013
 Problem:    Plus One
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_66
 Notes:
 Given a number represented as an array of digits, plus one to the number.

 Solution: Reverse the digits first.
 */

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        bool carrybit = true;
        for (int i = 0; i < digits.size() && carrybit; i++)
        {
            int sum = digits[i] + carrybit;
            digits[i] = sum % 10;
            carrybit = sum >= 10;
        }
        if (carrybit)
            digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
