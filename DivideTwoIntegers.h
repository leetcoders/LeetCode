/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 8, 2013
 Problem:    Divide Two Integers
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_29
 Notes:
 Divide two integers without using multiplication, division and mod operator.

 Solution: Use << operator.
           1. iterative way.
           2. recursive way.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        return divide_1(dividend, divisor);
    }

    int divide_1(int dividend, int divisor) {
        bool sign = dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0;
        unsigned long un_dividend = abs(dividend), un_divisor = abs(divisor);

        int res = 0;
        while (un_dividend >= un_divisor)
        {
            unsigned long long temp = un_divisor;
            int shift = 0;
            while ((temp << 1) <= un_dividend)
            {
                temp <<= 1;
                shift++;
            }

            un_dividend -= temp;
            res += 1 << shift;
        }

        return sign ? -res : res;
    }

    int divide_2(int dividend, int divisor) {
        bool sign = dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0;
        unsigned long un_dividend = abs(dividend), un_divisor = abs(divisor);
        int res = divideRe(un_dividend, un_divisor);
        return sign ? -res : res;
    }

    int divideRe(unsigned long dividend, unsigned long divisor)
    {
        if (dividend < divisor)
            return 0;

        unsigned long long temp = divisor;
        int shift = 0;
        while ((temp << 1) <= dividend)
        {
            temp <<= 1;
            shift++;
        }
        return (1 << shift) + divideRe(dividend - temp, divisor);
    }
};
