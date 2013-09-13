/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 12, 2013
 Update:     Sep 13, 2013
 Problem:    Scramble String
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_87
 Notes:
 Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
 Below is one possible representation of s1 = "great":
       great
      /     \
     gr    eat
    / \    /  \
   g   r  e   at
  / \
 a   t
 To scramble the string, we may choose any non-leaf node and swap its two children.
 For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
       rgeat
      /     \
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

 Solution: 1. 3-dimensional dp. Contributed by yinlinglin. I really appreciate it!
              'dp[k][i][j] == true' means string s1(start from i, length k) is a scrambled string of 
              string s2(start from j, length k).
           2. Recursion + pruning.
 */

class Solution {
public:
    bool isScramble(string s1, string s2) {
        return isScramble_2(s1, s2);
    }
    
    // solution 1: dp.
    bool isScramble_1(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int N = s1.size();
        bool dp[N+1][N][N];
        for (int k = 1; k <= N; ++k)
            for (int i = 0; i <= N-k; ++i)
                for (int j = 0; j <= N-k; ++j)
                {
                    dp[k][i][j] = false;
                    if (k == 1) 
                        dp[1][i][j] = (s1[i] == s2[j]);
                    for (int p = 1; p < k && !dp[k][i][j]; ++p)
                        if (dp[p][i][j] && dp[k-p][i+p][j+p] || dp[p][i][j+k-p] && dp[k-p][i+p][j])
                            dp[k][i][j] = true;
                }
        return dp[N][0][0];
    }

    // solution 2: recursion + pruning.
    typedef string::iterator Iterator;
    
    bool isScramble_2(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        return isScrambleRe(s1.begin(), s2.begin(), s1.size());
    }

    bool isScrambleRe(Iterator s1, Iterator s2, int len) {
        if (!hasSameLetters(s1, s2, len)) return false;
        if (len == 0 || len == 1) return true;
        for (int i = 1; i < len; ++i)  // highlight
            if (isScrambleRe(s1, s2, i) && isScrambleRe(s1 + i, s2 + i, len - i) ||
                isScrambleRe(s1, s2 + len - i, i) && isScrambleRe(s1 + i, s2, len - i))
                return true;
        return false;
    }

    bool hasSameLetters(Iterator s1, Iterator s2, int len) {
        int count[256] = {0};
        for (int i = 0; i < len; ++i) count[*s1++]++;
        for (int i = 0; i < len; ++i) count[*s2++]--;
        for (int i = 0; i < 256; ++i)
            if (count[i] != 0) return false;
        return true;
    }
};
