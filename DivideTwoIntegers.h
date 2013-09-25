/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 8, 2013
 Update:     Sep 25, 2013
 Problem:    Divide Two Integers
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_29
 Notes:
 Divide two integers without using multiplication, division and mod operator.

 Solution: Use << operator.
*/

class Solution {
public:
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
};
