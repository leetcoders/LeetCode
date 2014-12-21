/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Co-author:  King, higuige@gmail.com
 Date:       May 26, 2013
 Update:     Oct 26, 2014
 Problem:    Regular Expression Matching
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_10
 Notes:
 Implement regular expression matching with support for '.' and '*'.
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "a*") ? true
 isMatch("aa", ".*") ? true
 isMatch("ab", ".*") ? true
 isMatch("aab", "c*a*b") ? true

 Solution: Both of the two solutions are from http://leetcode.com/2011/09/regular-expression-matching.html .
 Solution 3: DP.
 Solution 4: DP. O(n^2) Time, O(n) Space.
*/

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        
        if (*(p+1) == '*') // next is '*'
        {
            while ((*s == *p || *p == '.') && *s != '\0')
            {
                if (isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s, p+2);
        }
        
        if (*s == '\0') return false;
        return (*s == *p || *p == '.') && isMatch(s+1, p+1);
    }
    
    bool isMatch_2(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        if ((*s != '\0') && (*s == *p || *p =='.')) {
            if (*(p+1) == '*') {
                return isMatch(s+1,p) || isMatch(s, p+2);
            } else return isMatch(s+1, p+1);
        }
        return *(p+1) == '*' && isMatch(s, p+2);
    }

    bool isMatch_3(const char *s, const char *p) {
         int l1 = strlen(s), l2 = strlen(p), k;
         char ch1, ch2;
         vector<vector<bool> > f(l1 + 1, vector<bool>(l2 + 1,false));
         f[0][0] = true;
         for (int i = 2; i <= l2; i ++)
            if (*(p + i - 1) == '*') f[0][i] = f[0][i - 2];
         for (int i = 1; i <= l1; i ++)
            for (int j = 1; j <= l2; j ++) {
                ch1 = *(s + i - 1); ch2 = *(p + j - 1);
                if (ch2 != '*') f[i][j] = f[i - 1][j - 1] && (ch1 == ch2 || ch2 == '.');
                else {
                    f[i][j] = f[i][j - 2];
                    if (*(s + i - 1) == *(p + j - 2) || *(p + j - 2) == '.') f[i][j] = f[i][j] | f[i - 1][j];
                }
            }
         return f[l1][l2];
    }
    bool isMatch_4(const char *s, const char *p) {
        int l1 = strlen(s), l2 = strlen(p), k;
        char ch1, ch2;
        vector<vector<bool> > f(2, vector<bool>(l2 + 1,false));
        f[0][0] = true;
        for (int i = 2; i <= l2; i ++)
            if (*(p + i - 1) == '*') f[0][i] = f[0][i - 2];
        for (int i = 1; i <= l1; i ++){
            for (int j = 1; j <= l2; j ++) {
                ch1 = *(s + i - 1); ch2 = *(p + j - 1);
                if (ch2 != '*') f[1][j] = f[0][j - 1] && (ch1 == ch2 || ch2 == '.');
                else {
                    f[1][j] = f[1][j - 2];
                    if (*(s + i - 1) == *(p + j - 2) || *(p + j - 2) == '.') f[1][j] = f[1][j] | f[0][j];
                }
            }
            f[0] = f[1];
        }
        return f[0][l2];
    }
};
