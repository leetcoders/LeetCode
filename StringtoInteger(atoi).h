/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 17, 2013
 Problem:    String to Integer (atoi)
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_8
 Notes:
 Implement atoi to convert a string to an integer.
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not 
 see below and ask yourself what are the possible input cases.
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 You are responsible to gather all the input requirements up front.

 Requirements for atoi:
 The function first discards as many whitespace characters as necessary until the first 
 non-whitespace character is found. Then, starting from this character, takes an optional
 initial plus or minus sign followed by as many numerical digits as possible, and interprets 
 them as a numerical value.
 The string can contain additional characters after those that form the integral number, which 
 are ignored and have no effect on the behavior of this function.
 If the first sequence of non-whitespace characters in str is not a valid integral number, or 
 if no such sequence exists because either str is empty or it contains only whitespace characters, 
 no conversion is performed.
 If no valid conversion could be performed, a zero value is returned. If the correct value is out 
 of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

 Solution: ...
 */

class Solution {
public:
    int atoi(const char *str) {
        long long res = 0;
        int i = 0;
        while (isspace(str[i]))
            i++;

        bool positive = true;
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '-')
                positive = false;
            i++;
        }

        while (isdigit(str[i]) && str[i] != '\0')
        {
            res = res * 10 + (str[i] - '0');
            i++;
        }

        res = positive ? res : -res;
        if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;

        return (int)res;
    }
};