/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Jul 8, 2013
 Update:     Nov 18, 2014
 Problem:    Divide Two Integers
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/divide-two-integers/
 Notes:
 Divide two integers without using multiplication, division and mod operator.

 Solution: Use << operator.
*/

class Solution {
public:
    // Solution 1. Bottom->Up
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        bool flag = dividend > 0 && divisor < 0 || 
                    dividend < 0 && divisor > 0;
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        int res = 0;
        while (dividendll >= divisorll)
        {
            long long div = divisorll;
            int quot = 1;
            while ((div << 1) <= dividendll) {
                div <<= 1;
                quot <<= 1;
            }
            dividendll -= div;
            res += quot;
        }
        return flag ? -res : res;
    }
    // Solution 2. Top->Down
    int divide_2(int dividend, int divisor) {
        assert(divisor != 0);
        bool flag = dividend > 0 && divisor < 0 || 
                    dividend < 0 && divisor > 0;
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        int res = 0;
        long long d = divisorll, q = 1;
        while ((d << 1) <= dividendll) {
            d <<= 1;
            q <<= 1;
        }
        while (dividendll >= divisorll) {
            if (dividendll >= d) {
                dividendll -= d;
                res += q;
            }
            d >>= 1;
            q >>= 1;
        }
        return flag ? -res : res;
    }
};
