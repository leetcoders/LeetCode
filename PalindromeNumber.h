/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Aug 22, 2013
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

 Solution: 1. Count the number of digits first (traverse once) then check the digits from both sides to center.
           2. Reverse the number, then check to see if x == reverse(x).
           3. Recursion (interesting but a little hard to understand).
 */

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome1(x);
    }
    
    // solution 1
    bool isPalindrome1(int x) {
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

    // solution 2
    bool isPalindrome2(int x) {
        if (x < 0) return false;
        return x == reverse(x);
    }

    int reverse(int x)
    {
        int rev = 0;
        while (x) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
    
    // solution 3
    bool isPalindrome3(int x) {
        return isPalindromeRe(x, x);
    }
    
    bool isPalindromeRe(int x, int &y) {
        if (x < 0) return false;
        if (x == 0) return true;
        if (isPalindromeRe(x / 10, y) && x % 10 == y % 10)
        {
            y /= 10;
            return true;
        }
        return false;
    }
};
