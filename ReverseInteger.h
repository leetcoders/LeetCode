/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Update:     Sep 1, 2013
 Problem:    Reverse Integer
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_7
 Notes:
 Reverse digits of an integer.
 Example1: x = 123, return 321
 Example2: x = -123, return -321

 Have you thought about this?
 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

 Solution: Use % and / iteratively.
 */
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while (x) {
            res = res * 10 + (x % 10);
            x /= 10;
        }
        assert(res >= INT_MIN && res <= INT_MAX);
        return res;
    }
};