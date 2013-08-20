/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 12, 2013
 Update:     Aug 21, 2013
 Problem:    Scramble String
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_87
 Notes:
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 Below is one possible representation of s1 = "great":
      great
      /    \
     gr    eat
    / \    /  \
   g   r  e   at
  / \
 a   t
 To scramble the string, we may choose any non-leaf node and swap its two children.
 For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
       rgeat
      /    \
     rg    eat
    / \    /  \
   r   g  e   at
  / \
 a   t
 We say that "rgeat" is a scrambled string of "great".
 Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
      rgtae
      /    \
     rg    tae
    / \    /  \
   r   g  ta  e
  / \
 t   a
 We say that "rgtae" is a scrambled string of "great".
 Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

 Solution: Recursively try every possible combinations.
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScrambleRe(s1, 0, s1.size() - 1, s2, 0, s2.size() - 1);
    }

    bool isScrambleRe(const string &s1, int b1, int e1, const string &s2, int b2, int e2) {
        if (!hasSameLetters(s1, b1, e1, s2, b2, e2)) return false;
        int length = e1 - b1 + 1;
        if (length == 0 || length == 1) return true;

        for (int i = 0; i < length - 1; ++i)  // highlight
            if (isScrambleRe(s1, b1, b1 + i, s2, b2, b2 + i) && isScrambleRe(s1, b1 + i + 1, e1, s2, b2 + i + 1, e2) ||
                isScrambleRe(s1, b1, b1 + i, s2, e2 - i, e2) && isScrambleRe(s1, b1 + i + 1, e1, s2, b2, e2 - i - 1))
                return true;
        return false;
    }

    bool hasSameLetters(const string &s1, int b1, int e1, const string &s2, int b2, int e2) {
        if (e1 - b1 != e2 - b2) return false;
        int count[256] = {0};
        for (int i = b1; i <= e1; ++i) count[s1[i]]++;
        for (int i = b2; i <= e2; ++i) count[s2[i]]--;
        for (int i = 0; i < 256; ++i) 
            if (count[i] != 0) return false;
        return true;
    }
};
