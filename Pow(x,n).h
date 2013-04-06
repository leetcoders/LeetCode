/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Problem:    Pow(x, n)
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_50
 Notes:
 Implement pow(x, n).
 
 Solution: recursion.
 */

class Solution {
public:
    double pow(double x, int n) {
        if (x == 1)
            return 1;
        if (x < 0)
            return (n%2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        if (n < 0)
            return 1.0/pow(x, -n);
        
        double a = pow(x, n/2);
        if (n%2 ==0)
            return a*a;
        else
            return x*a*a;
    }
};