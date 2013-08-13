/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Problem:    Roman to Integer
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_13
 Notes:
 Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.

 Solution: <map> (clean)
 */

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        int res = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        res += roman[s[s.size()-1]];
        return res;
    }
};
