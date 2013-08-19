/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Aug 20, 2013
 Problem:    Wildcard Matching
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_44
 Notes:
 Implement wildcard pattern matching with support for '?' and '*'.
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "*") ? true
 isMatch("aa", "a*") ? true
 isMatch("ab", "?*") ? true
 isMatch("aab", "c*a*b") ? false

 Solution: ...
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *ss = NULL, *pp = NULL;
        while (*s)
        {
            if (*p == '?' || *s == *p)
            {
                s++;
                p++;
            }
            else if (*p == '*')
            {
                while (*p == '*') p++;
                if (!*p) return true;
                ss = s;
                pp = p;
            }
            else if ((!*p || *s != *p) && ss)
            {
                s = ++ss;
                p = pp;
            }
            else
            {
                return false;
            }
        }
        while (*p == '*') p++;
        return !*s && !*p;
    }
};