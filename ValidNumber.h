/*
 Author:     Annie Kim, anniekim.pku@gmail.com : Andy, nkuwjg@gmail.com
 Date:       May 25, 2013
 Update:     Feb 7, 2015
 Problem:    Valid Number
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/valid-number/
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

 Solution: This finite-state machine solution. Learn from fuwutu & snakeDling.
*/

class Solution {
public:
    bool isNumber_1(const char *s) {
        enum InputType {INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT};
        int transitionTable[][SPACEEND] = 
        { /* 0   1   2   3   4   5  */
             0,  1,  2,  3,  4,  0, // 0: INVALID
             0,  1,  2,  3,  4,  0, // 1: SPACE
             0,  0,  0,  3,  4,  0, // 2: SIGN
             0,  6,  0,  3,  7,  5, // 3: DIGIT
             0,  0,  0,  7,  0,  0, // 4: DOT
             0,  0,  2,  8,  0,  0, // 5: EXPONENT
             0,  6,  0,  0,  0,  0, // 6: END WITH SPACE
             0,  6,  0,  7,  0,  5, // 7: DOT AND DIGIT
             0,  6,  0,  8,  0,  0, // 8: END WITH SPACE OR DIGIT
        };
        
        InputType last = INVALID;
        while (*s != '\0')
        {
            InputType state = INVALID;
            if (*s == ' ')
                state = SPACE;
            else if (isdigit(*s))
                state = DIGIT;
            else if (*s == '+' || *s == '-')
                state = SIGN;
            else if (*s == 'e')
                state = EXPONENT;
            else if (*s == '.')
                state = DOT;
            last = (InputType) transitionTable[last][state];
            if (last == INVALID) return false;
            s++;
        }
        bool validFinal[] = {0, 0, 0, 1, 0, 0, 1, 1, 1};
        return validFinal[last];
    }
    bool isNumber_2(const char *s) {
        bool dot = false, digit = false, exp = false;
        while (*s  == ' ') ++s;
        if (*s == '-' || *s == '+') ++s;
        if (*s == 0) return false;
        for (;*s != '\0' && *s != ' '; ++s) {
            if (isdigit(*s)) digit = true;
            else if (*s == 'e' || *s == 'E') {
                if (exp == true || digit == false || *(s+1) ==' ' || *(s+1) =='\0') return false;
                exp = true;
            } else if (*s == '.') {
                if (dot == true || exp == true) return false; 
                if (digit == false && (*(s+1) ==' ' || *(s+1) =='\0')) return false;
                dot = true;
            } else if (*s == '-' || *s == '+') {
                if (*(s+1) == ' ' || *(s+1) == '\0') return false;
                if (*(s-1) != 'e' && *(s-1) != 'E') return false;
            } else return false;
        }
        while (*s  == ' ') ++s;
        return *s == '\0';
    }
};