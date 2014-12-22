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
    //Top -> Down
    int divide_1(int dividend, int divisor) {
        assert(divisor != 0);
        bool flag = (dividend < 0) ^ (divisor < 0);
        long long dividendll = abs((long long)dividend);
        long long divisorll = abs((long long)divisor);
        long long res = 0;
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
        if (flag == true) res = -res;
        if (res > INT_MAX) return INT_MAX;
        return res;
    }
    //bottom -> up
    int divide(int dividend, int divisor) {
        assert(divisor != 0);
        bool flag = (dividend < 0) ^ (divisor < 0);
        long long Dividend = abs((long long)dividend);
        long long Divisor = abs((long long)divisor);
        long long res = 0;
        while (Dividend >= Divisor) {
            long long c = Divisor;
            for (int i = 0; (c << i) <= Dividend; ++i) {
                Dividend -= (c << i);
                res += (1 << i);
            }
        }
        if (flag == true) res = -res;
        if (res > INT_MAX) return INT_MAX;
        return res;
    }
};