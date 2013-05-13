/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Problem:    Roman to Integer
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_13
 Notes:
 Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.

 Solution: 1. A direct way (faster)
           2. <map> (clean)
 */

class Solution {
public:
    int romanToInt(string s) {
        return romanToInt_1(s);
    }

    int romanToInt_1(string s) {
        int N = s.size();
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == 'M')
                res += 1000;
            else if (s[i] == 'L')
                res += 50;
            else if (s[i] == 'D')
                res += 500;
            else if (s[i] == 'V')
                res += 5;
            else if (s[i] == 'C')
            {
                if (i < N-1 && (s[i+1] == 'M' || s[i+1] == 'D'))
                    res -= 100;
                else 
                    res += 100;
            }
            else if (s[i] == 'X')
            {
                if (i < N-1 && (s[i+1] == 'C' || s[i+1] == 'L'))
                    res -= 10;
                else 
                    res += 10;
            }
            else if (s[i] == 'I')
            {
                if (i < N-1 && (s[i+1] == 'X' || s[i+1] == 'V'))
                    res -= 1;
                else 
                    res += 1;
            }
        }
        return res;
    }

    int romanToInt_2(string s) {
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