/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Aug 29, 2013
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
        int carry = 1, N = digits.size();
        for (int i = N-1; i >= 0 && carry; --i)
        {
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }
        if (carry == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
