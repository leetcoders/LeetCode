/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Problem:    Valid Number
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_65
 Notes:
 Validate if a given string is numeric.
 Some examples:
 "0" => true
 " 0.1 " => true
 "abc" => false
 "1 a" => false
 "2e10" => true
 Note: It is intended for the problem statement to be ambiguous. You should gather all 
 requirements up front before implementing one.

 Solution: The most annoying problem that I've ever met:)
*/

class Solution {
public:
    bool isNumber(const char *s) {
        int i = 0;
        while (s[i] == ' ')
            i++;
        if (s[i] == '+' || s[i] == '-')
            i++;
        if (s[i] == '\0')
            return false;

        bool isE = false;
        bool isFloat = false;
        bool isNum = false;
        while (s[i] != '\0' && s[i] != ' ')
        {
            if (s[i] == '.')
            {
                if (isFloat || isE)
                    return false;
                if (!isNum && !isdigit(s[i+1]))
                    return false;
                isFloat = true;
            }
            else if (s[i] == 'e')
            {
                if (isE || !isNum)
                    return false;
                if (!isdigit(s[i+1]) && s[i+1] != '+' &&  s[i+1] != '-')
                    return false;
                isE = true;
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (s[i-1] != 'e' || s[i+1] == '\0')
                    return false;
            }
            else if (isdigit(s[i]))
            {
                isNum = true;
            }
            else
            {
                return false;
            }

            i++;
        }
        while (s[i] == ' ')
            i++;
        return s[i] == '\0';
    }
};