/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Update:     Aug 13, 2013
 Problem:    Valid Number
 Difficulty: Hard
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

 Solution: This finite-state machine solution is from fuwutu. Perfect solution!
 Link: https://github.com/fuwutu/LeetCode/blob/master/Valid%20Number.cpp
*/

class Solution
{
public:
    bool isNumber(const char *s)
    {
        enum InputType
        {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        
        int transitionTable[][NUM_INPUTS] =
        {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };
        
        int state = 0;
        while (*s != '\0')
        {
            InputType inputType = INVALID;
            if (isspace(*s))
                inputType = SPACE;
            else if (*s == '+' || *s == '-')
                inputType = SIGN;
            else if (isdigit(*s))
                inputType = DIGIT;
            else if (*s == '.')
                inputType = DOT;
            else if (*s == 'e' || *s == 'E')
                inputType = EXPONENT;
            
            state = transitionTable[state][inputType];
            
            if (state == -1)
                return false;
            else
                ++s;
        }
        
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};
