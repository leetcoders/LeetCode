/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 10, 2013
 Problem:    Unique Binary Search Trees
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_96
 Notes:
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3

 Solution: dp.
*/

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= i; j++)
                dp[i] += dp[j-1] * dp[i-j];
        return dp[n];
    }
};