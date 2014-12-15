/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 17, 2013
 Update:     Dec 14, 2014(By wangjingui@outlook.com)
 Problem:    String to Integer (atoi)
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/string-to-integer-atoi/solution/
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

 Solution: 1. use long type to store the result to deal with overflow.
           2. To deal with overflow, inspect the current number before multiplication. 
            If the current number is greater than 214748364, we know it is going to overflow.
            On the other hand, if the current number is equal to 214748364, 
            we know that it will overflow only when the current digit is greater than or equal to 8..
 */

class Solution {
public:
    int atoi_1(const char *str) {
        if (!str) return 0;
        while (*str == ' ') str++;
        bool positive = true;
        if (*str == '+' || *str == '-') {
            positive = *str == '+';
            str++;
        }
        long long res = 0;
        while (isdigit(*str)) {
            res = res * 10 + (*str - '0');
            str++;
        }
        res = positive ? res : -res;
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return (int)res;
    }
    int atoi_2(const char *str) {
        if(str == NULL) return 0;
        int res = 0;
        bool sign = true;
        while(*str == ' ') str++;
        if(*str == '+' || *str == '-') {
            sign = *str == '+';
            str++;
        }
        while(isdigit(*str)) {
            if(res > INT_MAX/10 || (res == INT_MAX / 10 && *str - '0' > INT_MAX % 10)){
                return sign ? INT_MAX : INT_MIN;
            }
            res =  res * 10 + *str - '0';
            str++;
        }
        return  sign ? res : -res;
    }
};
