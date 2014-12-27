/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Aug 20, 2013
 Problem:    Wildcard Matching
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/wildcard-matching/
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
        const char *sBackup = NULL, *pBackup = NULL;
        while (*s != '\0') {
            if (*p == '*') {
                while (*p == '*') ++p;
                if (*p == '\0') return true;
                sBackup = s;
                pBackup = p;
            }
            if (*p == '?' || *s == *p) {
                ++s, ++p;
            } else {
                if (!sBackup) return false;
                s = ++sBackup;
                p = pBackup;
            }
        }
        while (*p == '*') ++p;
        return *s == '\0' && *p == '\0';
    }
};