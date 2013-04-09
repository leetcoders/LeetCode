/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Plus One
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_66
 Notes:
 Given a number represented as an array of digits, plus one to the number.

 Solution: ...
 */

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry_bit = false;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            carry_bit = (digits[i] + 1) >= 10;
            digits[i] = (digits[i] + 1) % 10;
            if (!carry_bit)
                break;
        }
        
        if (carry_bit)
        {
            vector<int> res(1, 1);
            for (int i = 0; i < digits.size(); i++)
                res.push_back(digits[i]);
            return res;
        }
        
        return digits;
    }
};