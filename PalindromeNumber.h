/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Palindrome Number
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_9
 Notes:
 Determine whether an integer is a palindrome. Do this without extra space.
 Some hints:
 Could negative integers be palindromes? (ie, -1) (No!)
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", 
 you know that the reversed integer might overflow. How would you handle such case?
 There is a more generic way of solving this problem.

 Solution: Calculate the number of digits first.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int d = 1;
        while (x / d >= 10) d *= 10;
        while (d > 1)
        {
            if (x % 10 != x / d)
                return false;
            x = x % d / 10;
            d /= 100;
        }
        return true;
    }
};